/* ��N�G�K���Y��(collapse hit) */

#include <ansi.h>
#define SKILL_NAME   "collapse hit"
#define SKILL_NAME_C "�K���Y��"
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
    	case 189: me->set_skill_require(skill, 1500000); break; // ���d3 : 189��190
    	case 149: me->set_skill_require(skill, 1000000); break; // ���d2 : 149��150
    	case  99: me->set_skill_require(skill, 500000);  break; // ���d1 :  99��100
    	default:  me->set_skill_require(skill, lv*lv*5); break;
    }
}

// ��ʧ���
int perform_action(object me, string act, object target)
{
    if( !objectp(me) || !objectp(target) ) return 0;


    return notify_fail("�ثe�o�ӧޯ��٨S��@�����A�Э@�ߵ��@�q�ɶ��C\n");
    if( me->is_busy() )
        return notify_fail("�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
    
    if( act != "attack" )
        return notify_fail("�ثe" + SKILL_NAME_C + "�u�� attack �\\��C\n");
    
    if( !me->is_fighting(target) )
        return notify_fail("�A�å��M���b�԰���...\n");
    
    if( me->query_skill(SKILL_NAME, 1) < 50 )
        return notify_fail("�A����O�����H�ϥγo�@�ۡC\n");
    
    if( me->query_stat("mp") < 300 )
        return notify_fail("�A���骬�p���ΡA����ϥ�" + SKILL_NAME_C + "�C\n");

    message_vision("$N�ɳܤ@�n�A���Ⱶ�s�X���A�ϥX"HIW"�y"HIB + SKILL_NAME_C + HIW"�z"NOR"�����K�x���V$n����U�B...\n", me, target);

    return 1;
}
