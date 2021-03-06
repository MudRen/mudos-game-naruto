/* savage_hit.c 暴擊
   加的程度太高...改成 1 級加 1 點攻擊力量 by mouse
*/

#include <ansi.h>
#define SKILL_NAME  "savage hit"
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
    ability = ability + me->query_skill("savage hit");
    if( !type ) return ability;

    // 增加經驗
    me->improve_skill(SKILL_NAME, 1);
    return ability;
}
