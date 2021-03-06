#include <ansi.h>
#define SKILL_NAME "wolf blade"
#define SKILL_NAME_C "刀狼流"
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

int evade(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*9/40;
}

// 檢查是否能使用技能
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( act != "flow" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "有 flow 這個功\能。\n");
        return 0;
    }

    if( me->query_skill("blade", 1) < 50 || sk < 20 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk ) {
        tell_object(me, "你的狀態無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_condition("bladewolf", 1) != 0) {
        tell_object(me, "你已經在使用" + SKILL_NAME_C + "技巧了。\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    message_vision("$N"HIC"使出攻守一體技巧『"HIG+SKILL_NAME_C+HIC"』！\n"NOR, me);

    cnd["name"] = HIG+SKILL_NAME_C+NOR;
    cnd["duration"] = sk/2;
    cnd["intimidate"] = sk/2;
    cnd["evade"] = sk/2;

    me->set_condition("bladewolf", cnd);
    me->damage_stat("mp", sk, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    // 檢查是否能使用技能
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}
