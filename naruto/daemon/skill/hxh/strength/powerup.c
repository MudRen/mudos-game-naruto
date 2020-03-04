/* powerup.c
  by mouse 2007/7/28
*/

#include <ansi.h>
#define SKILL_NAME "powerup"
#define SKILL_NAME_C "��O"
#define SKILL_CLASS "strength"

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
        case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
        case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
        case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
        default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// �P�R�@���v�T
int sock(object me, object target, int ability, int type)
{
    if( me->query_skill("strength") < 100 ) return ability;
    return ability + me->query_skill(SKILL_NAME)/20;
}

// �P�R�@���ˮ`����%, ��l��(150%)
int sockPower(object me, object target, int ability, int type)
{
    if( me->query_skill("strength") < 100 ) return ability;
    return ability + me->query_skill(SKILL_NAME)/4;
}
