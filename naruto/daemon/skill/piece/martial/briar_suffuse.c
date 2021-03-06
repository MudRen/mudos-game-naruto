#include <ansi.h>
#define SKILL_NAME "briar suffuse"
#define SKILL_NAME_C "荊棘之路"
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

// 迴避能力影響
int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/25;
}

int attack(object me, object target, int ability, int type)
{
    string *name = ({ "肩膀", "右大腿", "肚子", "右臂", "背部", "右小腿", "胸口", 
                      "左大腿", "左臂", "左小腿", "右腕", "左腕", "軀幹", "身軀",
                      "膝蓋\", "膝部", "護額", "衣衫", "內褲", "錢袋", "鼻孔",
                      "肚臍", "褲子", "護目鏡", "眼鏡", });

    int sk, i, number;
    object *targets;

    if( !type ) return ability;

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();
    number = (sk/66) - 1;
    if( number <= 0 ) number = 0;

    // 判斷是否啟動
    if( me->query_stat("mp") < 200 ) return ability;
    if( me->query_skill("martial", 1) < 180 ) return ability;
    if( me->query_skill("gun whip", 1) < 100 ) return ability;
    if( sk < 40 ) return ability;

    if( sk < 80 ) {                          // 20~80 級 5%
        if( random(sk) < sk*19/20 ) return ability;
    } else if( sk < 150 ) {                  // 81~150 級 10%
        if( random(sk) < sk*9/10 ) return ability;
    } else {                                 // 151~200 級 20%
        if( random(sk) < sk*8/10 ) return ability;
    }
    message_vision("$N揮動著雙手刺向四周"HIM"『"HIG"荊棘之路"HIM"』"NOR"極快的手法讓人無法瞧見$N是否有拿武器。"NOR"！\n", me, target);

    // 多人攻擊判定
    for(i=0;i<sizeof(targets);i++) {
        if( i > number ) break;   // 最多攻擊三人
        if( targets[i]->is_busy() ) {
            message_vision("\t$n似乎已經無法動彈。\n", me, targets[i]);
        } else {
            if( random(me->query_ability("exact")+me->query_ability("wittiness") ) <
                random(targets[i]->query_ability("evade")+targets[i]->query_ability("intimidate")) ) {

                message_vision("\t$n用自己的武器格擋預測攻擊路線，順利的閃過攻擊。\n", me, targets[i]);
            } else {
                targets[i]->start_busy(sk/33);
                message_vision("\t$n眼花撩亂之際被攻擊擊中，忽然感覺全身麻痺無法行動。\n", me, targets[i]);
                me->improve_skill(SKILL_NAME, 1);
            }
        }
    }
    // 扣除mp
    me->damage_stat("mp", 50*i, me);
    return ability;
}
