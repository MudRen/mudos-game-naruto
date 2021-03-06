/* 白眼(white eyes) by mouse 2007/8/12 */

#include <ansi.h>
#define SKILL_NAME "white eyes"
#define SKILL_NAME_C "白眼"
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

// 攻擊技巧影響
int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/40;
}

// 防禦技巧影響
int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// 檢查是否能使用技能
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( act != "open" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "只有 open 這個功\能。\n");
        return 0;
    }

    if( sk < 50 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < 300 ) {
        tell_object(me, "你的狀態無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_condition("white_eyes", 1) != 0) {
        tell_object(me, "你的"HIW + SKILL_NAME_C + NOR"目前已經在開眼狀態了。\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    me->damage_stat("mp", 300, me);
    message_vision("$N大喝一聲："HIG"日向家血繼限界"HIW"『白眼』"HIG"！開！"NOR"\n\n只見"HIW"$N"NOR"的眼睛四周青筋浮現，瞳孔漸漸顯現出來！\n\n"NOR, me);

    cnd["name"] = HIW+SKILL_NAME_C+NOR;
    cnd["duration"] = 900;
    cnd["evade"] = sk;

    me->set_condition("white_eyes", cnd);

    // 增加技能經驗
    me->improve_skill(SKILL_NAME, 1);
}

// 使用絕招
int perform_action(object me, string act, object target)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !isCast(me, act, target, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}