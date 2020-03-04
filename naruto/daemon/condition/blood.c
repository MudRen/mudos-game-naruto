#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("blood");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    int i = me->query_stat_maximum("hp")/100;
    if( i > 100 ) i = 100 + random(50);
 
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision("$N"RED"���ˤf���G�}�l¡�X�F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    // �����ͩR��, �ԭz
    message_vision( sprintf("$N"RED"���ˤf�������y�X�A��...(%d) %s\n", i, COMBAT_D->report_status(me) ), me);

    if( objectp(cnd_data["from"]) ) me->damage_stat("hp", i, cnd_data["from"]);
    else me->damage_stat("hp", i, me);
}