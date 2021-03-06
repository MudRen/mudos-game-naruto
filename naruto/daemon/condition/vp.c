/* 毒念力變化試用 */

#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("vp");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIG"$N身上的中毒似乎已經減輕了。\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    // 扣除生命值, 敘述
    message_vision( sprintf(GRN"$N似乎中毒了...臉色有些難看。(%d) %s\n", 10, COMBAT_D->report_status(me) ), me);
    if( objectp(cnd_data["from"]) ) me->damage_stat("hp", 10, cnd_data["from"]);
    else me->damage_stat("hp", 10, me);
}