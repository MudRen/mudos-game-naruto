#include <ansi.h>

inherit CONDITION;

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$N" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$N" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$N" + HIR + ratio + "%" + HIK"]\n"NOR;
}

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("iceball");
}
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {

        // ���a�缾�a�S���B�z
        if( userp(cnd_data["from"]) && userp(me) ) {
            me->delete_condition(cnd);
            return;
        }
        // �䤣��ϥΪ̴N�H�K���I��
        if( !objectp(cnd_data["from"]) ) me->receive_damage(50, me);
        else me->receive_damage(cnd_data["damage"], cnd_data["from"]);

        message_vision(HIC"�B�������F�|�P���v�T�A���M��t�z����"NOR"$N"HIC"���쭫�СI("HIR+cnd_data["damage"]+HIW")"+report_status(this_object())+""NOR, me);
        me->delete_condition(cnd);
        return;
    }
    // �ԭz
    message_vision("$N"HIW"�Q�B�᪺���l�o�X�}�}�H��...\n"NOR, me);
}
