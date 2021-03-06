#include <ansi.h>
#define SKILL_NAME "gun whip"
#define SKILL_NAME_C "指槍•鞭"
#define SKILL_CLASS "martial"

inherit SKILL;

void create()
{
    seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

string query_class() { return SKILL_CLASS; }

void skill_advanced(object me, string skill)
{
    int lv = me->query_skill(skill, 1);
    switch( lv ) {
        case 189: me->set_skill_require(skill, 1500000); break; // 關卡3 : 189升190
        case 149: me->set_skill_require(skill, 1000000); break; // 關卡2 : 149升150
        case  99: me->set_skill_require(skill, 500000);  break; // 關卡1 :  99升100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// 取得傷害
int getDamage(object me, object target, int sk)
{
    int damage;
    object wp;

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    if( sk < 100 ) return damage/4;          // 25%
    else if( sk < 120 ) return damage*7/25;  // 28%
    else if( sk < 150 ) return damage/3;     // 33%
    else if( sk < 180 ) return damage*13/50; // 36%
    else if( sk < 199 ) return damage*2/5;   // 40%
    else return damage*50/100;               // 50%

    return damage;
}

// 技能使用後 
void setEffect(object me, int sk, int hit)
{
    if( !hit ) {
        me->damage_stat("mp", sk/30, me);
    } else {
        me->damage_stat("mp", sk/15, me);
    }
    me->improve_skill(SKILL_NAME, 1);
}

int autoCasting(object me, object target, object weapon)
{
    string *name = ({ "肩膀", "右大腿", "肚子", "右臂", "背部", "右小腿", "胸口", 
                      "左大腿", "左臂", "左小腿", "右腕", "左腕", "軀幹", "身軀",
                      "膝蓋\", "膝部", "護額", "衣衫", "內褲", "錢袋", "鼻孔",
                      "肚臍", "褲子", "護目鏡", "眼鏡", });

    string msg = name[random(sizeof(name))];
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // 判斷是否啟動
    if( me->query_stat("mp") < sk/15 ) return 1;
    if( me->query_skill("martial", 1) < 40 ) return 1;
    if( sk < 20 ) return 1;

    if( sk < 80 ) {                          
        if( random(sk) < sk*9/10 ) return 1;  // 20~80 級 10%
    } else if( sk < 150 ) {                  
        if( random(sk) < sk*19/20 ) return 1; // 81~150 級 15%
    } else {                                 
        if( random(sk) < sk*4/5 ) return 1;   // 151~200 級 20%
    }

    message_vision("$N朝$n衝了過去，"HIW"『"HIB"指槍•鞭"HIW"』"NOR"在攻擊前右手忽然像鞭一樣甩動抽向$n"+msg+"！\n", me, target);

    hit = COMBAT_D->isHit(me, target);

    if( !hit ) {
        message_vision("但是$N的攻擊方向似乎沒有算準，揚起了地上一片的灰塵...\n", me, target);

    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("「啪」地一聲打中$n"+msg+"，$n因"+msg+"受創而痛苦不堪(%d) %s\n", damage, COMBAT_D->report_status(target) ), me, target);
        if( me->query_skill("martial", 1) >= 60 && !target->is_busy() ) {
            target->start_busy((sk-20)/60);
        }
    }
    setEffect(me, sk, hit);
    return 1;
}