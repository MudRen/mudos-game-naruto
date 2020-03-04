/* �ղ�(white eyes) by mouse 2007/8/12 */

#include <ansi.h>
#define SKILL_NAME "white eyes"
#define SKILL_NAME_C "�ղ�"
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

// �����ޥ��v�T
int intimidate(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)*3/40;
}

// ���m�ޥ��v�T
int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/20;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, object target, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "open" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� open �o�ӥ\\��C\n");
        return 0;
    }

    if( sk < 50 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < 300 ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("white_eyes", 1) != 0) {
        tell_object(me, "�A��"HIW + SKILL_NAME_C + NOR"�ثe�w�g�b�}�����A�F�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]);

    me->damage_stat("mp", 300, me);
    message_vision("$N�j�ܤ@�n�G"HIG"��V�a���~����"HIW"�y�ղ��z"HIG"�I�}�I"NOR"\n\n�u��"HIW"$N"NOR"�������|�P�C���B�{�A���պ�����{�X�ӡI\n\n"NOR, me);

    cnd["name"] = HIW+SKILL_NAME_C+NOR;
    cnd["duration"] = 900;
    cnd["evade"] = sk;

    me->set_condition("white_eyes", cnd);

    // �W�[�ޯ�g��
    me->improve_skill(SKILL_NAME, 1);
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !isCast(me, act, target, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}