// ��ø�Z��

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("fb");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIY"$N������^�_�쥿�`���A�C\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);
    
    mcnd["duration"] = cnd_data["duration"];

    me->add_temp("apply/attack", mcnd["attack"] );         // �W�[�����O�q
    me->add_temp("apply/intimidate", mcnd["intimidate"] ); // �W�[�����ޥ�
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "fb" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("fb");
    if( !cnd_data ) return;

    me->add_temp("apply/attack", -cnd_data["attack"] );
    me->add_temp("apply/intimidate", -cnd_data["intimidate"] );
}