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
    	case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
    	case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
    	case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
    	default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// ���m�O�v�T
int defend(object me, object target, int ability, int type)
{
    // �|�v�T���m�O
    int value = ability + me->query_skill(SKILL_NAME);
    if( !type ) return value;
    
    // �ϥΤ@���K�|�W�[�g��
    me->improve_skill(SKILL_NAME, 1);
    return value;
}
