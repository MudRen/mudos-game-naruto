// 石灰

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("calcification");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    me->set("no_defend", 1);      // 不能防禦
    me->set("no_evade", 1);       // 不能迴避
}
void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "calcification" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("calcification");
    if( !cnd_data ) return;

    me->delete("no_defend");
    me->delete("no_evade");
}
