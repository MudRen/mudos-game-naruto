/* �Ȭr 
   �̷ӥͩR�̤j��1%���������r���A

   ��Ƶ��c
   ([ "duration": �ɮ� ])
*/
#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("scorpion_poison");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    int i = me->query_stat_maximum("hp")/100;
    if( i > 200 ) i = 200;

    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIM"$N���W�����r���G�w�g��F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
    // �����ͩR��, �ԭz
    message_vision( sprintf("$N"MAG"�y��@�}�h�W�A�ˤf�y�X�¦��G...(%d) %s\n", i, COMBAT_D->report_status(me) ), me);
    if( objectp(cnd_data["from"]) ) me->damage_stat("hp", i, cnd_data["from"]);
    else me->damage_stat("hp", i, me);
}