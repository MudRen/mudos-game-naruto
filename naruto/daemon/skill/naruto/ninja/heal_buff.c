/* �v¡�N(heal buff) by mouse 2007/8/12 */

#include <ansi.h>
#define SKILL_NAME "heal buff"
#define SKILL_NAME_C "�v¡�N"
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

// ���m�ޥ��v�T
int wittiness(object me, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/40;
}

// �R����O�v�T
int exact(object me, object target, int ability, int type)
{
    return ability + me->query_skill(SKILL_NAME)/10;
}

// �ˬd�O�_��ϥΧޯ�
int isCast(object me, string act, int sk)
{
    if( !objectp(me) ) return 0;

    if( me->is_busy() ) {
        tell_object(me, "�A���b���L���A�S�Ũϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    if( act != "heal" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� heal �@�إ\\��C\n");
        return 0;
    }

    if( sk < 40 || me->query_skill("ninja") < 60 ) {
        tell_object(me, "�A����O�����H�ϥγo�ӧޯ�C\n");
        return 0;
    }

    if( me->query_stat("mp") < sk ) {
        tell_object(me, "�A�S���������d�J�Ԩϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, object target, int sk)
{
    mapping cnd = ([]);

    if( objectp(target) ) {
        if( userp(me) && !userp(target) ) {
            write("�A����缾�a�H�~���F��ϥγo�ۡC\n");
            return;
        }
        if( sk < 80 ) {
            write(target->query("name")+"�w�g�Q�v¡�N�����~�ҥ]��F�C\n");
            return;
        }
    } else target = me;

    if( target->query_condition("heal_buff") != 0) {
        write(target->query("name")+"�w�g�Q" + SKILL_NAME_C + "�����~�ҥ]��F�C\n");
        return;
    }
    message_vision("$N�s�򵲤F�X�ӦL�A�k�⭹��������$n���B�Y�@�I�A"HIW"�@�}�ե�"NOR"Ţ�n$n����...\n", me, target);

    cnd["name"] = HIW"�v¡�N"NOR;
    if( me == target ) cnd["duration"] = sk/20;
    else cnd["duration"] = sk/40;
    cnd["heal"] = sk/40;

    if( me->is_fighting() ) {
        tell_object(this_player(),HIW"(�A���ߨϥ�" + SKILL_NAME_C + "�@�ɶ��L�k���)\n"NOR);
        me->start_busy(2);
    }

    target->set_condition("heal_buff", cnd);
    me->damage_stat("mp", sk, me);
    me->improve_skill(SKILL_NAME, 1);
}

int perform_action(object me, string act, object target)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, target, sk);
    return 1;
}
