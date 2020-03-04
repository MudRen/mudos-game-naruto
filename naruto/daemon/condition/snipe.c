// ��������

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("snipe");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIY"$N���`�N�O�L�׶����A�������Iè�b�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);
    
    mcnd["duration"] = cnd_data["duration"];
    
    me->add_temp("apply/exact", mcnd["exact"] );          // �W�[�R����O
    me->add_temp("apply/armor", -mcnd["defend"] );        // ��֨��m�O�q
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "snipe" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("snipe");
    if( !cnd_data ) return;

    me->add_temp("apply/exact", -cnd_data["exact"] );
    me->add_temp("apply/armor", cnd_data["defend"] );
}