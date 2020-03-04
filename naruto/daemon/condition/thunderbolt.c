#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("thunderbolt");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( !me->is_fighting() ) {
        message_vision(HIK"�]������԰�$N�N�¶����ѤF�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIK"�]�����ݮɶ��Ӫ��ҥH�¶������F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}