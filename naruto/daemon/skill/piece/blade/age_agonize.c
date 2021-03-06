#include <ansi.h>
#define SKILL_NAME "age agonize"
#define SKILL_NAME_C "三十六煩惱鳳"
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

    if( me->query_condition("age_cd") ) {
        tell_object(me, "你的氣力目前還無法發出斬擊。\n");
        return 0;
    }

    if( !me->query_temp("weapon/righthand") && !me->query_temp("weapon/lefthand") && !me->query_temp("weapon/twohanded")) {
        tell_object(me, "這是一刀流技能，必須拿一把武器才能使用。\n");
        return 0;
    }

    if( me->query_skill("blade", 1) < 160 || sk < 40 || me->query_skill("chivy tiger") < 70 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
        tell_object(me, "你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

// 計算是否命中
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->intimidate(me, 1)*2;
    j = COMBAT_D->evade(target, me, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// 取得傷害
int getDamage(object me, object target, int sk)
{
    int damage;

    // 傷害為對手生命最大值
    if( sk < 81 ) {
        damage = target->query_stat_maximum("hp")/100;    // 1%
        if( damage > 500 ) damage = 500;
    } else if( sk < 121 ) {
        damage = target->query_stat_maximum("hp")/50;     // 2%
        if( damage > 1000 ) damage = 1000;
    } else if( sk < 161 ) {
        damage = target->query_stat_maximum("hp")/25;     // 4%
        if( damage > 2000 ) damage = 2000;
    } else if( sk < 200 ) {
        damage = target->query_stat_maximum("hp")*2/25;   // 8%
        if( damage > 4000 ) damage = 4000;
    } else {
        damage = target->query_stat_maximum("hp")/10;     // 10%
        if( damage > 5000 ) damage = 5000;
    }
    return damage;
}

// 技能使用後 
void setEffect(object me, int sk, int hit)
{
    mapping cnd = ([]);

    if( !hit ) {
        me->start_busy(3);
        me->damage_stat("mp", sk/4, me);
    } else {
        me->start_busy(2);
        me->damage_stat("mp", sk/2, me);
    }
    cnd["name"] = HIW+"(CD)煩惱"+NOR;
    cnd["duration"] = 100;

    me->set_condition("age_cd", cnd);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // 檢查是否能使用技能
    if( !isCast(me, act, target, sk) ) return 1;

    message_vision("\n$N低聲唸著「三十六...」忽然手中長刀一揮"HIY"『"HIW"煩惱鳳"HIY"』"NOR"！刀氣直衝$n身前！\n"NOR, me, target);

    // 是否命中
    hit = isHit(me, target);

    if( !hit ) {
        message_vision("$N看準了刀氣的攻勢，一個翻滾避開了攻擊。\n\n", target);
    } else {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("刀氣從$n身上貫身而過，一口鮮血從$n嘴中噴了出來(%d) %s\n\n", damage, COMBAT_D->report_status(target) ), me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
