// 毛髮念控

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("hairstick");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !cnd_data["from"] ) {
        message_vision(HIW"\n因為操縱者已經死去，毛髮也沒有作用了。\n\n"NOR, me);
        me->delete_condition(cnd);
        return;
    } else if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIW"\n$N"HIW"的念力消耗殆盡，"NOR"毛髮軟化"HIW"脫離了$n"HIW"。\n\n"NOR, cnd_data["from"], me);
        me->delete_condition(cnd);
        return;
    } else if( !cnd_data["from"]->is_fighting(me) ) {
        message_vision(HIW"\n$N"HIW"不再攻擊$n"HIW"，將"NOR"毛髮"HIW"收了回去。\n\n"NOR, cnd_data["from"], me);
        me->delete_condition(cnd);
        return;
    }
}
