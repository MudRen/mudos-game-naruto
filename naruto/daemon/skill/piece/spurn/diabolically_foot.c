#include <ansi.h>
#define SKILL_NAME "diabolically foot"
#define SKILL_NAME_C "惡魔風腳"
#define SKILL_CLASS "spurn"

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
    return ability + me->query_skill(SKILL_NAME)/6;
}

// 檢查是否能使用技能
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "你現在沒有空使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    if( act != "atwirl" ) {
        tell_object(me, "目前" + SKILL_NAME_C + "有 atwirl 這個功\能。\n");
        return 0;
    }

    if( me->query_skill("spurn", 1) < 80 || sk < 20 ) {
        tell_object(me, "你的能力不足以使用這一招。\n");
        return 0;
    }

    if( me->query_condition("diabo_busy", 1) != 0) {
        tell_object(me, "必須等冷卻時間結束。\n");
        return 0;
    }

    if( me->query_stat("mp") < sk ) {
        tell_object(me, "你的狀態無法使用" + SKILL_NAME_C + "。\n");
        return 0;
    }

    return 1;
}

// 技能使用後 
void setEffect(object me, int sk)
{
    me->damage_stat("mp", sk, me);
    me->start_busy(2);
    me->improve_skill(SKILL_NAME, 1);
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    message_vision("$N"YEL"在原地高速旋轉使出『"HIR+SKILL_NAME_C+YEL"』！\n"NOR, me);

    cnd["name"] = YEL+SKILL_NAME_C+NOR;
    cnd["duration"] = sk/2;

    me->set_condition("diabo", cnd);

    cnd["name"] = HIY"(CD)惡魔"NOR;
    cnd["duration"] = sk;

    me->set_condition("diabo_busy", cnd);
}

int perform_action(object me, string act)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    // 檢查是否能使用技能
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, sk);

    setEffect(me, sk);
    return 1;
}
