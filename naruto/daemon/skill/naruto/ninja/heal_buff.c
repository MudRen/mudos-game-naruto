/* 治癒術(heal buff) by mouse 2007/8/12 */

#include <ansi.h>
#define SKILL_NAME "heal buff"
#define SKILL_NAME_C "治癒術"
#define SKILL_CLASS "ninja"

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

// 防禦技巧影響
int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/40;
}

// 命中能力影響
int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// 檢查是否能使用技能
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你正在忙碌中，沒空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( act != "heal" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "只有 heal 一種功\能。\n");
        return 0;
    }

    if( sk < 40 || me->query_skill("ninja") < 60 ) {
        tell_object(me, "你的能力不足以使用這個技能。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk ) {
        tell_object(me, "你沒有足夠的查克拉使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, object target, int sk)
{
    mapping cnd = ([]);

    if( objectp(target) ) {
        if( userp(me) && !userp(target) ) {
            write("你不能對玩家以外的東西使用這招。\n");
            return;
        }
        if( sk < 80 ) {
            write(target->query("name")+"已經被治癒術的光芒所包圍了。\n");
            return;
        }
    } else target = me;

    if( target->query_condition("heal_buff") != 0) {
        write(target->query("name")+"已經被" + SKILL_NAME_C + "的光芒所包圍了。\n");
        return;
    }
    message_vision("$N連續結了幾個印，右手食指輕輕往$n的額頭一點，"HIW"一陣白光"NOR"籠罩$n全身...\n", me, target);

    cnd["name"] = HIW"治癒術"NOR;
    if( me == target ) cnd["duration"] = sk/20;
    else cnd["duration"] = sk/40;
    cnd["heal"] = sk/40;

    if( me->is_fighting() ) {
        tell_object(this_player(),HIW"(你分心使用" + SKILL_NAME_C + "一時間無法行動)\n"NOR);
        me->start_busy(2);
    }

    target->set_condition("heal_buff", cnd);
    me->damage_stat("mp", sk, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    // 檢查是否能使用技能
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, target, sk);
    return 1;
}
