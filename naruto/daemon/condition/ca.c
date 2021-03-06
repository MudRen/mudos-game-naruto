// 細胞活化

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("ca");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }
    me->heal_stat("ap", cnd_data["heal"] );      // 恢復AP值
    me->heal_stat("hp", cnd_data["heal"] );      // 恢復HP值
}
