/* 柔拳法-八卦六十四掌(soft fist) 
   by mouse 2007/8/12
*/

#include <ansi.h>
#define SKILL_NAME "soft fist"
#define SKILL_NAME_C "八卦六十四掌"
#define SKILL_CLASS "force"

inherit SKILL;

int number;

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

// 攻擊技巧影響
int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*13/200;
}

// 攻擊力量影響
int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/20;
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

    if( sk < 50 || me->query_skill("force", 1) < 60 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/5 ) {
        tell_object(me, "你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_condition("soft_cd") ) {
        tell_object(me, SKILL_NAME_C + "必須集中完成後才能再次使用。\n");
        return 0;
    }

    return 1;
}

// 計算是否命中
int isHit(object me, object target)
{
    int hit, meHit, targetHit;

    meHit = COMBAT_D->intimidate(me, 1);
    targetHit = COMBAT_D->wittiness(target, 1);

    me->add_temp("apply/exact", meHit);
    target->add_temp("apply/evade", targetHit);

    hit = COMBAT_D->isHit(me, target);

    me->add_temp("apply/exact", -meHit);
    target->add_temp("apply/evade", -targetHit);

    return hit;
}

// 取得傷害
int getDamage(object me, object target, int sk)
{
    int damage, raiseDamage;
    object wp;

    // 先取得八掛掌的掌數
    switch( sk ) {
        case 0..100: number = random(16); break;
        case 101..140: number = random(32); break;
        case 141..160: number = random(32) + 16; break;
        case 161..180: number = random(32) + 32; break;
        case 181..199: number = random(16) + 48; break;
        case 200: number = 64; break;
    }
    raiseDamage = number*10 + sk + me->query_skill("force");

    me->add_temp("apply/attack", raiseDamage);

    if( wp = me->query_temp("weapon/twohanded") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/righthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else if( wp = me->query_temp("weapon/lefthand") ) damage = COMBAT_D->isDamage(me, target, wp);
    else damage = COMBAT_D->isDamage(me, target, 0);

    me->add_temp("apply/attack", -raiseDamage);

    return damage;
}

// 白眼的打精傷害另外算
int apDamage(object me, object target, int sk)
{
    int ap;

    if( me->query_skill("white eyes") < 140 ) ap = sk;
    else if( me->query_skill("white eyes") < 160 ) ap = sk*2;
    else ap = sk*3;

    return ap;
}

// 技能使用後 
void setEffect(object me, int sk, int hit)
{
    mapping cnd = ([]);

    // 沒擊中、白眼狀態不同部份再計算
    if( !hit ) {
        me->damage_stat("mp", sk/10, me);
    } else {
        if( me->query_condition("white_eyes") ) {
            me->improve_skill(SKILL_NAME, 1);
        } else {
            me->damage_stat("mp", sk/5, me);
        }
    }
    cnd["name"] = HIW+"(CD)八卦"+NOR;
    cnd["duration"] = 4;

    // 不管是否擊中都應該有cd
    me->set_condition("soft_cd", cnd);
    me->improve_skill(SKILL_NAME, 1);
    me->start_busy(1);
}

// 手動攻擊
int perform_action(object me, string act, object target)
{
    int sk, damage, hit, white, ap;

    sk = me->query_skill(SKILL_NAME, 1);
    white = me->query_skill("white eyes", 1);

    // 檢查是否能使用技能
    if( !isCast(me, act, target, sk) ) return 1;

    // 檢查命中
    hit = isHit(me, target);

    // 取得傷害，八卦掌的次數要先算出來
    damage = getDamage(me, target, sk);

    message_vision("\n$N兩手放平，擺\出日向家族傳承之拳法"HIW"『柔拳』"NOR"的起手式...「"HIW"柔拳法"NOR"•"HIR"八卦"+chinese_number(number)+"掌"NOR"」\n", me, target);
    if( hit ) {
        if( me->query_condition("white_eyes") && white > 99 ) {
            ap = apDamage(me, target, sk);

            target->receive_damage(damage, me);

            // 當對手 ap 比打精傷還少的時候就直接設成精 1
            if( target->query_stat("ap") < ap ) target->set_stat_current("ap", 1);
            else target->damage_stat("ap", ap, me);

            message_vision(sprintf("$N配合白眼看穿$n全身氣脈活動，連起數掌將$n內勁打亂導致氣血逆流(%d) %s\n\n", damage, report_status(target) ), me, target);
        } else {
            target->receive_damage(damage, me);
            message_vision(sprintf("$N連出數掌擊向$n身體的各大經絡，打的$n口吐鮮血難過至極(%d) %s\n\n", damage, report_status(target) ), me, target);
        }
    } else {
        message_vision("但是$N發覺$n早已有心防備此招，因此立刻收招了。\n\n", me, target);
    }
    setEffect(me, sk, hit);
    return 1;
}
