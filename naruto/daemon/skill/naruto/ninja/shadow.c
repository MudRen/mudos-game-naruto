/* �v�����N(shadow) by mouse 2007/8/12 */

#include <ansi.h>
#define SKILL_NAME "shadow"
#define SKILL_NAME_C "�v�����N"
#define SKILL_CLASS "ninja"

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

// �ϥε���
int perform_action(object me, string act, object target)
{
    string msg;
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���ŨϥΡC\n");
    if( me->query_skill(SKILL_NAME) < 40 ) return notify_fail("�A�٤���N�v�����N���Φۦp�C\n");

    switch( act ) {
        case "defend": me->set_temp("SHADOW_TEMP", 1);
                     msg = "�A�M�w�U���n�ϥ�"HIB"���m��"NOR"�v�����U�ԡC\n";
                     break;
        case "attack": me->set_temp("SHADOW_TEMP", 2);
                     msg = "�A�M�w�U���n�ϥ�"HIR"������"NOR"�v�����U�ԡC\n";
                     break;
        case "none": me->delete_temp("SHADOW_TEMP");
                     msg = "�A�M�w�U���n�ϥ�"HIG"������"NOR"�v�����U�ԡC\n";
                     break;
        default: return notify_fail("�A�i�H���w�n�ϥέ��ث��A���v�����Cperform shadow.attack|defend|none\n"); break;
    }
    tell_object(me,msg);
    return 1;
}
