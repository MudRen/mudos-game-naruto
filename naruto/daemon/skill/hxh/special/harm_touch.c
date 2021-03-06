// harm_touch.c 特質系-傷害之觸
// 2005/10/22 -Tmr

/*
☉ 傷害之觸(harm touch)

古老相傳傷害之觸是一種非常特殊的傷害能力，在一瞬間能造成敵人的重大傷害。

使用條件：特質系(special) 30級以上 及 傷害之觸(harm touch) 25 級以上。
使用方法：perform special.harming [對像]
傷害力  ：(特質系等級*5 + 傷害之觸等級*10)

傷害之觸:  25 級 | 50 級 | 75 級 | 100 級 | 125 級 | 150 級 | 175 級 | 200 級 |
停用時間:  18 hr | 14 hr | 10 hr |   8 hr |   6 hr |   4 hr |   2 hr |   1 hr |
*/

#include <ansi.h>
#define SKILL_NAME   "harm touch"
#define SKILL_NAME_C "傷害之觸"
#define SKILL_CLASS  "special"
#define HOUR         1800

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

int getDuration(int lv) 
{
    switch( lv/25 ) {
        case 1: return 18*HOUR;
        case 2: return 14*HOUR;
        case 3: return 10*HOUR;
        case 4: return 8*HOUR;
        case 5: return 6*HOUR;
        case 6: return 4*HOUR;
        case 7: return 2*HOUR;
        case 8: return 1*HOUR;
    }
    return 20*HOUR;
}

// 檢查是否能使用技能
int isCast(object me, string act, object target, int sk, int ssk)
{
    mapping cnd = ([]);

    if( !objectp(me) || !objectp(target) ) {
        tell_object(me, "傷害之觸使用方法： perform harm touch.harming on [對像]\n");
        return 0;
    }

    if( !me->is_fighting(target) ) {
        tell_object(me, "你並未和對方在戰鬥中...\n");
        return 0;
    }

    if( me->query_condition("harm_touch_cond" ) ) {
        tell_object(me, "你身體的狀態還沒有恢復，暫時無法使用傷害之觸。\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "你正忙著。\n");
        return 0;
    }

    if( act != "harming" ) {
        tell_object(me, "" + SKILL_NAME_C + "只有 harming 的功\能。\n");
        return 0;
    }

    if( sk < 25 || ssk < 30  ) {
        tell_object(me, "你目前的能力還不足以使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_stat("mp") < 1 ) {
        tell_object(me, "你的念力值低於 1，無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

// 使用絕招
int perform_action(object me, string act, object target)
{
    int sk, ssk, dmg, time;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME, 1);
    ssk = me->query_skill("special", 1);

    if( !isCast(me, act, target, sk, ssk) ) return 1;

    dmg = sk*10 + ssk*5;
    message_vision( HIG"$N的雙手長滿劇毒的惡瘤，輕輕地觸碰了$n一下...\n" NOR, me, target);

    target->receive_damage(dmg, me);
    message_vision( HIR "$n發出一陣淒厲的叫聲，受到了 " + dmg + " 點的可怕傷害！！" + COMBAT_D->report_status(target) +"\n" NOR, me, target);

    me->damage_stat("mp", 1, me);
    me->improve_skill( SKILL_NAME, 1);

    time = getDuration(sk);

    cnd["name"] = HIK"(CD)傷害"NOR;
    cnd["duration"] = time;
    cnd["no_clear"] = 1;
    me->set_condition("harm_touch_cond", cnd);
    me->start_busy(2);
    return 1;
}
