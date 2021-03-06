/* 體術：八門崩擊(collapse hit) */

#include <ansi.h>
#define SKILL_NAME   "collapse hit"
#define SKILL_NAME_C "八門崩擊"
#define SKILL_CLASS  "force"

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

// 手動攻擊
int perform_action(object me, string act, object target)
{
    if( !objectp(me) || !objectp(target) ) return 0;


    return notify_fail("目前這個技能還沒實作完成，請耐心等一段時間。\n");
    if( me->is_busy() )
        return notify_fail("你現在沒有空使用" + SKILL_NAME_C + "。\n");
    
    if( act != "attack" )
        return notify_fail("目前" + SKILL_NAME_C + "只有 attack 功\能。\n");
    
    if( !me->is_fighting(target) )
        return notify_fail("你並未和對方在戰鬥中...\n");
    
    if( me->query_skill(SKILL_NAME, 1) < 50 )
        return notify_fail("你的能力不足以使用這一招。\n");
    
    if( me->query_stat("mp") < 300 )
        return notify_fail("你身體狀況不佳，不能使用" + SKILL_NAME_C + "。\n");

    message_vision("$N暴喝一聲，雙手接連出擊，使出"HIW"『"HIB + SKILL_NAME_C + HIW"』"NOR"瞬間八掌擊向$n身體各處...\n", me, target);

    return 1;
}
