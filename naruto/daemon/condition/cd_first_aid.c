/* cd_first_aid.c
   ��Ϫ�CD
*/

#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("cd_first_aid");
}

void condition_update(object me, string cnd, mixed cnd_data)
{
    int heal;
    
    if( !living(me) ) return;
    
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }
}
