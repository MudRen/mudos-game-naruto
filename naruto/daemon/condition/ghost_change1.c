// �����ഫ�Τ@����

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("ghost_change1");
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);
    
    mcnd["duration"] = cnd_data["duration"];
    
    me->add_temp("apply/"+mcnd["ability"], mcnd["str"] );   // �W�[
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "ghost_change1" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("ghost_change1");
    if( !cnd_data ) return;

    me->add_temp("apply/"+cnd_data["ability"], -cnd_data["str"] );   // ���
    me->delete("ghost_change/"+cnd_data["ability"]);
}
