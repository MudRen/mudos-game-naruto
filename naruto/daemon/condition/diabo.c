#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("diabo");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    mapping mcnd;
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIY"$N�}�W�����~�����h�h�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}