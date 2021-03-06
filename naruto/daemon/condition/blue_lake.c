// 水藍之湖

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("blue_lake");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( me->query_temp("blue_lake") >= 10 ) {
        message_vision(HIC"清涼的湖水令$N傷口快速好轉起來。\n"NOR, me);
        me->heal_stat("hp", 50);
        me->set_temp("blue_lake", 0);
    }
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        tell_object(me, HIC"湖水的涼意逐漸遠離你了。\n"NOR);
        me->delete_temp("blue_lake");
        me->delete_condition(cnd);
        return;
    }
    me->add_temp("blue_lake", 1);
}
void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "blue_lake" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("blue_lake");
    if( !cnd_data ) return;

    // 以防萬一，在這裡也刪一次temp
    me->delete_temp("blue_lake");
}
