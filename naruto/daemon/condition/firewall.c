// 火牆

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("firewall");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !me->is_fighting() ) {
        message_vision(HIR"\n結束戰鬥後$N立刻將火牆的念力收回。\n\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIR"\n$N"HIR"的念力消耗殆盡，火牆的效果已經消失。\n\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}
