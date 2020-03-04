/* �ԳN�G�ӭM����(cell activation)
   �ק� buff �ɮġB�N buff ���� by mouse 2007/8/14
*/

#include <ansi.h>
#define SKILL_NAME "cell activation"
#define SKILL_NAME_C "�ӭM����"
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

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A�{�b�S���Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "ca" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�� ca �o�ӥ\\��C\n");
        return 0;
    }

    if( sk < 20 || me->query_skill("ninja") < 20 ) {
        tell_object(me, "�A����O�����H�ϥγo�ӧޯ�C\n");
        return 0;
    }

    if( me->query_stat("mp") < sk*3/2) {
        tell_object(me, "�A�ثe�S���������d�J�ԨӨϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( me->query_condition("ca") && me->query_condition("ca2") ) {
        tell_object(me, "�A�ثe���M�b�ϥ�" + SKILL_NAME_C + "���C\n");
        return 0;
    }

    if( me->query_condition("ca2") &&
        me->query_stat("hp") >= me->query_stat_maximum("hp") &&
        me->query_stat("ap") >= me->query_stat_maximum("ap") ) {

        tell_object(me, "�A�{�b�����p�Q���}�n�A���ݭn����C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{

    mapping cnd = ([]);

    message_vision("$N����w�C�����L��b�B�Y�B���I�F�@�U�A�I�i�F"HIG+SKILL_NAME_C+NOR"�I�I\n", me);

    cnd["name"] = HIR"����"NOR;
    cnd["duration"] = 30;
    cnd["heal"] = sk/10;

    if( me->query_condition("ca") == 0 ) {
        write(HIR"(�A����G����d�J�Ԫ����ʡA�[�t�F�s���N�¡C)\n"NOR);
        me->set_condition("ca", cnd);
    }

    cnd["name"] = HIG+SKILL_NAME_C+NOR;
    cnd["duration"] = sk;
    cnd["str"] = sk/20;
    cnd["dex"] = sk/20;

    if( me->query_condition("ca2") == 0 ) {
        write(HIG"(�ӭM�}�l�����ܤơA�A�Pı������O�����F�C)\n"NOR);
        me->set_condition("ca2", cnd);
    }

    if( me->is_fighting() ) {
        tell_object(me, HIG"(�]���j��b�԰����I�i�ӭM���ơA�ȮɵL�k���)\n");
        me->start_busy(2);
    }

    me->damage_stat("mp", sk*3/2, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}
