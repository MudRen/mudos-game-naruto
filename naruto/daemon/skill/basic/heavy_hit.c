/*
   �������γB�b��p������O��í�w�{�סA���]�ثe���a�������O�� 100

   �u�w�w�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�q�w�w�w�w�w�t
   0                       50          75         100

   �Y�S�������ޯ�A�h�����O�� 50
   �Y������   1 �šA�h�����O�� 50 - 100 �������üƨ�
   �Y������ 100 �šA�h�����O�� 75 - 100 �������üƨ�
   �Y������ 200 �šA�h�����O�� 100
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
    	case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
    	case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
    	case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
    	default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// �����O�v�T
int attack(object me, object target, int ability, int type)
{
	int tmp, stable;
	
	stable = me->query_skill(SKILL_NAME);
	tmp = ability + ability * stable / 200;

    if( !type ) return tmp;
    ability = tmp + random(tmp-ability);

    // �W�[�g��
    me->improve_skill(SKILL_NAME, 1);
    
    return ability;
}