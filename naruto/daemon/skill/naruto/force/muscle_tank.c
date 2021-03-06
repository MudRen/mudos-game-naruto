// 重新開放 & 增加能力提升 by mouse 2007/8/14

#include <ansi.h>
#define SKILL_NAME "muscle tank"
#define SKILL_NAME_C "肉彈戰車"
#define SKILL_CLASS "force"

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

// 防禦力量影響
int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/4;
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

    if( sk < 50 || me->query_skill("force") < 50 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/10 ) {
        tell_object(me, "你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");
        return 0;
    }
    return 1;
}

// 計算是否命中
int isHit(object me, object target)
{
    int i, j;

    i = COMBAT_D->wittiness(me, 1);
    j = COMBAT_D->intimidate(target, 1);

    if( COMBAT_D->SkillHit(me, target, i, j) ) return 1;
    else return 0;
}

// 取得傷害
int getDamage(object me, object target, int sk)
{
    int raiseDamage, damage;
    object wp;

    if( me->query_attr("con") > 300 ) raiseDamage = 600 + sk*3 + me->query_skill("force")/2;
    else raiseDamage = me->query_attr("con")*2 + sk*3 + me->query_skill("force")/2;

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
    if( !hit ) {
        me->start_busy(5);
    } else {
        me->start_busy(2);
    }
    me->damage_stat("mp", sk/6, me);
    me->improve_skill(SKILL_NAME, 1);
}

// 手動攻擊
int perform_action(object me, string act, object target)
{
    int damage, sk, hit;

    sk = me->query_skill(SKILL_NAME, 1);

    // 檢查是否能使用技能
    if( !isCast(me, act, target, sk) ) return 1;

    // 是否命中
    hit = isHit(me, target);

    message_vision("\n$N突然跳起了肥大的身驅疾速向前滾動，使出"HIW"『"CYN+SKILL_NAME_C+HIW"』"NOR"朝著$n衝撞...\n", me, target);
    if( hit ) {
        damage = getDamage(me, target, sk);
        target->receive_damage(damage, me);
        message_vision( sprintf("$n來不及閃躲，便被這顆肉彈撞得哭爹喊娘...(%d) %s\n\n", damage, report_status(target) ), me, target);
    } else {
        message_vision("$N輕巧的躲過這一招...\n\n", target);
    }
    setEffect(me, sk, hit);
    return 1;
}
