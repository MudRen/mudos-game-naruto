/* �|�}�N(four foot) by mouse 2007/8/13 */

#include <ansi.h>
#define SKILL_NAME "four foot"
#define SKILL_NAME_C "�|�}�N"
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

// �R����O�v�T
int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/8;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "beast" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� beast �o�ӥ\\��C\n");
        return 0;
    }

    if( me->query_skill("ninja") < 60 || sk < 40 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < 200 ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("four_foot", 1) != 0) {
        tell_object(me, "�A�w�g�b" + SKILL_NAME_C + "���A�F�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    mapping cnd = ([]), weapons;
    string skill;
    object ob;

    message_vision("$N���L��N����Ĳ�I�a���A�o��"HIW"�y"HIR"�|�}���N"HIW"�z"NOR"�����B�{���~�몺�����I\n\n"NOR, me);

/*  �Z�������Ȯɮ���
    if( mapp(weapons = me->query_temp("weapon")) && sizeof(weapons) ) {
        foreach(skill, ob in weapons) ob->unequip();
        write("�]���A�o�ʥ|�}���N�A�ҥH�Ȯɤ���ϥΪZ���F�C\n");
    }
*/

    cnd["name"] = HIR+ SKILL_NAME_C +NOR;
    cnd["duration"] = sk*3/4;
    cnd["attack"] = sk/2;
    cnd["evade"] = sk/2;
    cnd["ap"] = sk*2;

    me->set_condition("four_foot", cnd);
    me->damage_stat("mp", 200, me);
    me->improve_skill(SKILL_NAME, 1);
}

// �ϥε���
int perform_action(object me, string act, object target)
{
    int sk;
    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}
