/* burn.c 
   ���ͩR�Ȫ��S�˪��A�A�ˮ`�̷�sk�����O�ӧ���

   ��Ƶ��c
   ([ "duration": �ɮ� ])
*/
#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("burn");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(YEL"$N"YEL"�Ҩ����S�˦��G�S�����Y���F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    // �����ͩR��, �ԭz
    message_vision( sprintf("$N"YEL"�Q�S�������b�a�W���u...(%d) %s\n", cnd_data["damage"], COMBAT_D->report_status(me) ), me);
    if( objectp(cnd_data["from"]) ) me->damage_stat("hp", cnd_data["damage"], cnd_data["from"]);
    else me->damage_stat("hp", cnd_data["damage"], me);
}