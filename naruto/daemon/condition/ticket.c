// �ɶU��

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("ticket");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIW"$N�L�k�����e����M�`�F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

// �Ϊ��A�����h�P�_�R���|����O�I
void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "ticket" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("ticket");
    if( !cnd_data ) return;

    me->delete_temp("ticket_card/"+cnd_data["ability"]);
    // �p�G���ɶU��̧ު��S��ĪG�A�b�ɶU�饢�Įɤ]�P�ɥ��h�ĪG
    if( me->query_condition("waterwall", 1) != 0) {
        write("�]���ɶU�骺�ĪG�����A�s�a�ۨ�L�\��]���h�ĥΤF�C\n");
        me->delete_condition("waterwall");
    }
}
