// ��v����

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("hairstick");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !cnd_data["from"] ) {
        message_vision(HIW"\n�]�����a�̤w�g���h�A��v�]�S���@�ΤF�C\n\n"NOR, me);
        me->delete_condition(cnd);
        return;
    } else if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIW"\n$N"HIW"�����O���Ӭp�ɡA"NOR"��v�n��"HIW"�����F$n"HIW"�C\n\n"NOR, cnd_data["from"], me);
        me->delete_condition(cnd);
        return;
    } else if( !cnd_data["from"]->is_fighting(me) ) {
        message_vision(HIW"\n$N"HIW"���A����$n"HIW"�A�N"NOR"��v"HIW"���F�^�h�C\n\n"NOR, cnd_data["from"], me);
        me->delete_condition(cnd);
        return;
    }
}
