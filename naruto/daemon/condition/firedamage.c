/* firedamage.c 
   ���ͩR�Ȫ��ۤ����A

   ��Ƶ��c
   ([ "duration": �ɮ� ])
*/
#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("firedamage");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIR"���V���G�w�g�����F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    // �����ͩR��, �ԭz
    message_vision( sprintf("$N"HIR"�Q���W�����V�N�a�z�z�j�s...(%d) %s\n", 50, COMBAT_D->report_status(me) ), me);
    if( objectp(cnd_data["from"]) ) me->damage_stat("hp", 50, cnd_data["from"]);
    else me->damage_stat("hp", 50, me);
}