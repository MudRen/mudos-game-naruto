#include <ansi.h>
#define SKILL_NAME "ketchup star"
#define SKILL_NAME_C "���X��P"
#define SKILL_CLASS "activity"

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

    if( !me->is_fighting() ) {
        tell_object(me, "�S�Ƥ��n�ø˦��C\n");
        return 0;
    }

    if( me->is_busy() ) {
        tell_object(me, "�A�ʼu���o�S��k�˦��C\n");
        return 0;
    }

    if( act != "die" ) {
        tell_object(me, "�ثe" + SKILL_NAME_C + "�u�� die �o�ӥ\\��C\n");
        return 0;
    }

    if( me->query_skill("activity", 1) < 50 || sk < 50 ) {
        tell_object(me, "�A����O�����H�ϥγo�@�ۡC\n");
        return 0;
    }

    if( me->query_stat("mp") < sk/2 ) {
        tell_object(me, "�A�����A�L�k�ϥ�" + SKILL_NAME_C + "�C\n");
        return 0;
    }

    return 1;
}

void do_perform(object me, int sk)
{
    write("�A�ϥX���ǡy"HIR+SKILL_NAME_C+NOR"�z�}�l�˦b�a�W�˦��C\n\n");
    message_vision(HIR"$N�u���v���G�s�@�n�A����Q�X�j�q�A��A�̫ᥢ��L�h�˦b�a�W�C\n"NOR, me);
    if( sk/4 > random(100) ) {
        message_vision("$n��$N�w�g���h�A�K�}�⤣���F�C\n"NOR, me, me->query_opponent());
        me->remove_all_killer();
    } else {
        message_vision("���G�@���a�ǭ���$N�����Y��$N���F�Ӥj�Q���A��ӬO�b�˦��I\n"NOR, me);
        me->start_busy(5);
    }
    me->damage_stat("mp", 10, me);
    me->improve_skill(SKILL_NAME, 1);
    return;
}
int perform_action(object me, string act)
{
    int sk;

    sk = me->query_skill(SKILL_NAME, 1);

    if( !objectp(me) ) return 0;

    // �ˬd�O�_��ϥΧޯ�
    if( !isCast(me, act, sk) ) return 1;

    do_perform(me, sk);
    return 1;
}