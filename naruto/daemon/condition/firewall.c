// ����

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("firewall");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !me->is_fighting() ) {
        message_vision(HIR"\n�����԰���$N�ߨ�N���𪺩��O���^�C\n\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIR"\n$N"HIR"�����O���Ӭp�ɡA���𪺮ĪG�w�g�����C\n\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}
