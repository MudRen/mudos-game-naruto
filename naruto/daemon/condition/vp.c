/* �r���O�ܤƸե� */

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
        message_vision(HIG"$N���W�����r���G�w�g��F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    // �����ͩR��, �ԭz
    message_vision( sprintf(GRN"$N���G���r�F...�y�⦳�����ݡC(%d) %s\n", 10, COMBAT_D->report_status(me) ), me);
    if( objectp(cnd_data["from"]) ) me->damage_stat("hp", 10, cnd_data["from"]);
    else me->damage_stat("hp", 10, me);
}