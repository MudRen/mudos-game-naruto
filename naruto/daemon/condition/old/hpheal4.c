/* hpheal4.c 
   狀態 hp 之恢復效能，恢復量是固定值

   資料結構
   ([ "duration": 時效 ])
*/
#include <ansi.h>

inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("hpheal4");
}

void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !living(me) ) return;
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        return;
    }

    // 恢復HP值
    me->heal_stat("hp", 40);
}


void food_condition_apply(object me, mapping cnd_data)
{
    mapping hpheal;
    
    if( !mapp(hpheal = me->query_condition("hpheal4")) )
        hpheal = ([]);
    
    hpheal["duration"] += cnd_data["duration"];
    hpheal["name"] = BRED"Ｓ級還陽術"NOR;
    
    if( hpheal["duration"] <= 0 ) hpheal["duration"] = 1;
    else if( hpheal["duration"] > 140 ) hpheal["duration"] = 140;
    
    me->set_condition("hpheal4", hpheal);
}

/*
void condition_apply(object me, string cnd, mapping cnd_data) { }
void condition_unapply(object me, string cnd, mapping cnd_data) { }
*/
