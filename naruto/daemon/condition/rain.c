// ���b�j�B

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("rain");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIB"$N���Ǫ����������h�A�B�]����F�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);
    
    mcnd["duration"] = cnd_data["duration"];
    
    me->add_temp("apply/intimidate", -mcnd["intimidate"] ); // ��֧����ޥ�
    me->add_temp("apply/exact", -mcnd["exact"] );           // ��֩R����O
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "rain" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("rain");
    if( !cnd_data ) return;

    // �������n�ɦ^
    me->add_temp("apply/intimidate", cnd_data["intimidate"] );
    me->add_temp("apply/exact", cnd_data["exact"] );
}
