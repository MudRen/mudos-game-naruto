#include <ansi.h>
#define SKILL_NAME  "combat"
#define SKILL_CLASS "basic"

inherit SKILL;

// �n�D DEMON_D �n���ޯ�
void create()
{
	seteuid(getuid());
    DAEMON_D->register_skill_daemon(SKILL_NAME);
}

// �ޯ����
string query_class() { return SKILL_CLASS; }

// ���ݭn enable 
// int valid_enable(string base_skill) { return base_skill == SKILL_BASE; }

// �ޯ�ɯū�|�I�s���禡�A�q�`�Ψӳ]�w�ɤU�@�ũһݪ��g��
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

// �R���v�v�T
int exact(object me, object target, int ability, int type)
{
    // �氫�ޥ� (combat) �|�v�T�R���v
    int value = ability + me->query_skill(SKILL_NAME)/2;
    if( !type ) return value;
    
    // �ϥΤ@���K�|�W�[�g��
    me->improve_skill(SKILL_NAME, 1);
    return value;
}

/*
int receiveDamage(object me, object target, int damage)
{
    if( userp(me) ) {
        message_vision(HIY"�j�������O��$N�M�j���J�A���@����$n"HIY"�������v�T�I (�ˮ`�l���G" + damage + ")\n"NOR, me, target);
        return 0;
    }
    return damage;
}
*/
