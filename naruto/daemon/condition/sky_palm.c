// �K���^��

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("sky_palm");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !me->is_fighting() ) {
        message_vision(HIW"\n$N�N�d�J�Ԧ^���A�����~��ϥ�"HIG"�K���^��"HIW"�C\n\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIW"\n$N�]���`�N�O���ΡA�u�n�Ȯɰ���"HIG"�K���^��"HIW"�C\n\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}
