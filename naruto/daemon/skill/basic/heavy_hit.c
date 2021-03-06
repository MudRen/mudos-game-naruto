/*
   重擊的用處在於計算攻擊力的穩定程度，假設目前玩家的攻擊力為 100

   ├───────────┼─────┼─────┤
   0                       50          75         100

   若沒有重擊技能，則攻擊力為 50
   若重擊為   1 級，則攻擊力為 50 - 100 之間做亂數取
   若重擊為 100 級，則攻擊力為 75 - 100 之間做亂數取
   若重擊為 200 級，則攻擊力為 100
*/
	   
#include <ansi.h>
#define SKILL_NAME  "heavy hit"
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

// 攻擊力影響
int attack(object me, object target, int ability, int type)
{
	int tmp, stable;
	
	stable = me->query_skill(SKILL_NAME);
	tmp = ability + ability * stable / 200;

    if( !type ) return tmp;
    ability = tmp + random(tmp-ability);

    // 增加經驗
    me->improve_skill(SKILL_NAME, 1);
    
    return ability;
}