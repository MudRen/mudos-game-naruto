// �K�����Q�|�x���uCD

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("soft_cd");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        tell_object(me, NOR"[�����O�q�����C]\n"NOR);
        me->delete_condition(cnd);
        return;
    }
}