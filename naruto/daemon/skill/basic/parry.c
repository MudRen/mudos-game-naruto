#include <ansi.h>
#define SKILL_NAME  "parry"
#define SKILL_CLASS "basic"

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

// 防禦力影響
int defend(object me, object target, int ability, int type)
{
    // 會影響防禦力
    int value = ability + me->query_skill(SKILL_NAME);
    if( !type ) return value;
    
    // 使用一次便會增加經驗
    me->improve_skill(SKILL_NAME, 1);
    return value;
}
