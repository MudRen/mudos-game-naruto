/* �ԳN�G���ƳN(double physique)
   �W�[��O���ɳ��� & �y�L�ק�ɮ� by mouse 2007/8/14
*/

#include <ansi.h>
#define SKILL_NAME "double physique"
#define SKILL_NAME_C "���ƳN"
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

// �����O�q�v�T
int attack(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*7/40;
}

// ���m�O�q�v�T
int defend(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/20;
}

void do_perform(object me)
{
    int sk;
    mapping cnd = ([]);

    sk = me->query_skill(SKILL_NAME , 1);

    if( sk < 30 || me->query_attr("con") < 30) {
        write("�A����O�����H�ϥέ��ƳN�C\n");
        return;
    }
    if( me->query_condition("dp") != 0) {
        write("�A�{�b���b�ϥέ��ƳN�C\n");
        return;
    }
    if( me->query_stat("mp") < sk*3/2) {
        write("�A�ثe�S���������d�J�ԨӨϥέ��ƳN�C\n");
        return;
    }
    me->damage_stat("mp", sk*3/2, me);

    message_vision("$N���⨳�t�����L�A�ɳܤ@�n�A�I�i�F"HIR+SKILL_NAME_C+NOR"�I�I\n", me);

    cnd["name"] = HIR+SKILL_NAME_C+NOR;
    cnd["duration"] = sk;
    cnd["hp"] =  sk*3;
    cnd["attack"] =  sk/3;
    cnd["armor"] =  sk/2;

    me->set_condition("dp", cnd);

    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    if( !objectp(me) ) return 0;
    if( me->is_busy() ) return notify_fail("�A�{�b�S���Ũϥ�"+SKILL_NAME_C+"�C\n");

    switch( act ) {
        case "dp": do_perform(me); break;
        default: return notify_fail("�ثe"+SKILL_NAME_C+"�� dp �o�ӥ\\��C\n"); break;
    }
    return 1;
}
