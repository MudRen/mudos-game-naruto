#include <ansi.h>
#define SKILL_NAME "chimera fay"
#define SKILL_NAME_C "幻想妖精"
#define SKILL_CLASS "activity"

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

int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/100;
}

int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*7/20;
}

// 檢查是否能使用技能
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( act != "assoil" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "有 assoil 這個功\能。\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 60 || sk < 50 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
        tell_object(me, "你的狀態無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( me->query_condition("elf", 1) ) {
        tell_object(me, "你已經在使用" + SKILL_NAME_C + "技巧了。\n");
        return 0;
    }

    if( !me->is_fighting() ) {
        tell_object(me, "沒在戰鬥有什麼好躲的。\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    object *team, member, staff;
    mapping cnd = ([]);

    team = me->query_team();

    // 先偵測身上有沒有天候棒
    if( !objectp(staff = present("_WEATHER_", me)) ) {
        write("你身上沒有天候棒怎麼用技能。\n");
        return;
    }
    message_vision("$N拿出"+staff->query("name")+"亂揮一通然後說道："HIW"海市蜃樓"NOR"•"HIC"幻想妖精"NOR"！\n"NOR, me);

    // 狀態共用
    cnd["name"] = HIC+SKILL_NAME_C+NOR;
    cnd["duration"] = sk/4;
    cnd["evade"] = sk/2;

    if( !pointerp(team = me->query_team() ) ) {
        message_vision(HIW"$N的身影漸漸消失在這裡...\n"NOR, me);
        me->set_condition("elf", cnd);
    } else {
        foreach(member in team) {
            // 組隊人員位置不同也沒有功能
            if( environment(me)->is_area() && !area_environment(me, member)) continue;
            message_vision(HIW"$N的身影漸漸消失在這裡...\n"NOR, member);
            member->set_condition("elf", cnd);
        }
    }
    me->damage_stat("mp", sk/2, me);
    me->improve_skill(SKILL_NAME, 1);
    return;
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
