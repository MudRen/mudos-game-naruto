// ��ø�E�n�d

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("slime");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIG"$N�����_���`�A���A�n�w�w�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);

    mcnd["duration"] = cnd_data["duration"];

    me->add_temp("apply/dex", mcnd["dex"] ); // �W�[�ӱ�
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "slime" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("slime");
    if( !cnd_data ) return;

    me->add_temp("apply/dex", -cnd_data["dex"] );
}