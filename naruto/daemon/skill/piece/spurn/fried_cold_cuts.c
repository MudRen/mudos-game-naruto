#include <ansi.h>
#define SKILL_NAME "fried cold cuts"
#define SKILL_NAME_C "油炸什錦拼盤"
#define SKILL_CLASS "spurn"

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

int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// 計算是否命中
int isHit(object me, object target)
{
    int hit, meHit, targetHit;

    meHit = me->query_ability("intimidate");
    targetHit = target->query_ability("evade");

    me->add_temp("apply/exact", meHit);
    target->add_temp("apply/evade", targetHit);
    hit = COMBAT_D->isHit(me, target);
    me->add_temp("apply/exact", -meHit);
    target->add_temp("apply/evade", -targetHit);

    return hit;
}

// 計算攻擊人數
int check_number(object me, int sk)
{
    int number;

    if( me->query_skill("spurn", 1) >= 70 ) {
        number = (sk/50) - 1;
        if( number <= 0 ) number = 0;
    } else {
        number = 0;
    }
    return number;
}

// 取得傷害
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk + me->query_skill("spurn")/2;

    if( wp = me->query_temp("weapon/twohanded") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/righthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else if( wp = me->query_temp("weapon/lefthand") ) raiseDamage -= COMBAT_D->isDamage(me, target, wp)*3/4;
    else raiseDamage -= COMBAT_D->isDamage(me, target, 0)*3/4;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

int autoCasting(object me, object target, object weapon)
{
    int damage, sk, i, number, hit;
    object *targets;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);
    targets = me->query_enemy();

    // 判斷是否啟動
    if( me->query_stat("mp") < sk/10 ) return 1;
    if( me->query_skill("spurn", 1) < 40 ) return 1;
    if( sk < 20 ) return 1;

    if( sk < 80 ) {                          // 20~80 級 5%
        if( random(sk) < sk*19/20 ) return 1;
    } else if( sk < 150 ) {                  // 81~150 級 10%
        if( random(sk) < sk*9/10 ) return 1;
    } else {                                 // 151~200 級 20%
        if( random(sk) < sk*8/10 ) return 1;
    }
    // 命中
    hit = isHit(me, target);

    // 人數
    number = check_number(me, sk);

    cnd["name"] = YEL+"燙傷狀態"+NOR;
    cnd["duration"] = 5;
    cnd["damage"] = sk/10;
    cnd["from"] = me;

    if( me->query_condition("diabo") ) message_vision("$N身子忽然倒立使出"HIR"『"YEL+BLINK"油炸什錦拼盤"NOR+HIR"』"NOR"踢擊周遭的敵人！\n", me, target);
    else message_vision("$N身子忽然倒立使出"HIR"『"YEL"什錦拼盤"NOR+HIR"』"NOR"踢擊周遭的敵人！\n", me, target);

    for(i=0;i<sizeof(targets);i++) {
        if( i > number ) break;   // 最多攻擊四人
        if( !hit ) {
            message_vision("$n向後一跳離開了$N的攻擊範圍...\n", me, targets[i]);
        } else {
            damage = getDamage(me, targets[i], sk);
            targets[i]->receive_damage(damage, me);
            if( me->query_condition("diabo") ) {
                targets[i]->set_condition("burn", cnd);
                message_vision( sprintf("$n像被燒紅的烙鐵燙到，身上印出一個大大的鞋印(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
            }
            else message_vision( sprintf("$n像被高速行駛的汽車撞到，整個人飛了出去痛苦不堪(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), me, targets[i]);
        }
    }
    me->damage_stat("mp", (sk/20)*i, me);
    me->improve_skill(SKILL_NAME, 1);
    return 1;
}
