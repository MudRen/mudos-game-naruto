/* 治療術 by mouse 2007/8/12 */

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("heal_buff");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( me->query_stat("hp") < me->query_stat_maximum("hp") ) {
        me->heal_stat("hp", me->query_stat_maximum("hp")*cnd_data["heal"]/100);
        message_vision("$N"HIW"身上的白光包住了的傷口，似乎正在為"NOR"$N"HIW"治療。\n"NOR, me);
        cnd_data["duration"]--;
    }
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }
    cnd_data["duration"]++;
}
