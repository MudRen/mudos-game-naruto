#include <ansi.h>
#define SKILL_NAME "ghost chop"
#define SKILL_NAME_C "鬼斬"
#define SKILL_CLASS "blade"

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

int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/2;
}

// 檢查是否能使用技能
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) || !objectp(target) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( act != "attack" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "只有 attack 功\能。\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "你並未和對方在戰鬥中...\n");
        return 0;
    }

    if( me->query_condition("ghost_cd") ) {
        tell_object(me, "必須等衝刺緩和才能再次使用。\n");
        return 0;
    }

    if( me->query_skill("blade", 1) < 30 || sk < 20 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/10 ) {
        tell_object(me, "你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

// 取得傷害
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    raiseDamage = sk + me->query_skill("blade")/2;

    if( me->query_attr("str") < 200 ) raiseDamage += me->query_attr("str");
    else raiseDamage += 200;

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// 技能使用後 
void setEffect(object me, int sk, int hit)
{
    mapping cnd = ([]);

    if( !hit ) {
        me->damage_stat("mp", sk/20, me);
        me->start_busy(2);
    } else {
        me->damage_stat("mp", sk/10, me);
        me->start_busy(1);
    }
    cnd["name"] = HIK+"(CD)鬼斬"+NOR;
    cnd["duration"] = 3;

    me->set_condition("ghost_cd", cnd);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit, i = 0;
    object *inv, item;

    sk = me->query_skill(SKILL_NAME, 1);
    inv = all_inventory(me);

    // 檢查是否能使用技能
    if( !isCast(me, act, target, sk) ) return 1;

    foreach(item in inv) {
        if( item->is_weapon() ) {
            i++;
        }
    }
    if( !me->query_temp("weapon/righthand") || !me->query_temp("weapon/lefthand") || i < 3 ) 
        return notify_fail("三刀流必須裝備兩把武器並攜帶第三把武器才能使用。\n");

    message_vision("\n$N將三把刀的力量聚於一點，使出"HIM"『"HIK"鬼斬"HIM"』"NOR"快速地衝往$n面前！\n", me, target);

    // 判斷命中
    hit = COMBAT_D->isHit(me, target);

    if( !hit ) {
        message_vision("$N看準了攻擊的縫細，身子一低閃過了攻擊。\n\n", target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("$n被三刀貫穿而過，衝擊力使身子飛了起來，在空中噴出大量鮮血(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
