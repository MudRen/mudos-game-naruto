// ���Ƨl��

#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("da");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }
    me->heal_stat("hp", cnd_data["hp"]);
}