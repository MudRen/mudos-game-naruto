// 借貸券 音療之術的短cd

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("music_heal");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        tell_object(me, NOR"[可以借貸了。]\n"NOR);
        me->delete_condition(cnd);
        return;
    }
}