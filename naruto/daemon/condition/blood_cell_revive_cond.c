// �ӭM�A�� 2005/10/26

#include <ansi.h>
inherit CONDITION;
#define COND_NAME "blood_cell_revive_cond"

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon(COND_NAME);
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }

    me->heal_stat("hp", cnd_data["heal"] );      // ��_HP��
}

/*
void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);
    
    mcnd["duration"] = cnd_data["duration"];
    
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != COND_NAME ) return;
    if( !cnd_data ) cnd_data = me->query_condition(COND_NAME);
    if( !cnd_data ) return;

}

*/
