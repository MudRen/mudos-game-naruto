// holy_hand_cond �t������
// tmr 2005/10/22

#include <ansi.h>
inherit CONDITION;
#define COND_NAME "holy_hand_cond"

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon( COND_NAME );
}

// �C update �@�� �����ɮĤ@�I..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }
}
