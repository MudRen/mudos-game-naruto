/* 忍術：倍化術(double physique)
   增加能力提升部份 & 稍微修改時效 by mouse 2007/8/14
*/

#include <ansi.h>
#define SKILL_NAME "double physique"
#define SKILL_NAME_C "倍化術"
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

// 攻擊力量影響
int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*7/40;
}

// 防禦力量影響
int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/20;
}

void do_perform(object me)
{
    int sk;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME , 1);

    if( sk < 30 || me->query_attr("con") < 30) {
        write("你的能力不足以使用倍化術。\n");
        return;
    }
    if( me->query_condition("dp") != 0) {
        write("你現在正在使用倍化術。\n");
        return;
    }
    if( me->query_stat("mp") < sk*3/2) {
        write("你目前沒有足夠的查克拉來使用倍化術。\n");
        return;
    }
    me->damage_stat("mp", sk*3/2, me);

    message_vision("$N雙手迅速的結印，暴喝一聲，施展了"HIR+SKILL_NAME_C+NOR"！！\n", me);

    cnd["name"] = HIR+SKILL_NAME_C+NOR;
    cnd["duration"] = sk;
    cnd["hp"] =  sk*3;
    cnd["attack"] =  sk/3;
    cnd["armor"] =  sk/2;

    me->set_condition("dp", cnd);

    // 增加技能經驗
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("你現在沒有空使用"+SKILL_NAME_C+"。\n");

    switch( act ) {
        case "dp": do_perform(me); break;
        default: return notify_fail("目前"+SKILL_NAME_C+"有 dp 這個功\能。\n"); break;
    }
    return 1;
}
