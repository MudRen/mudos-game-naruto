// 借貸券--水障壁跟發勁使用

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("waterwall");
}

// 每 update 一次 消秏時效一點..
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
    
    me->add_temp("apply/"+mcnd["ability"], mcnd["add"] );   // 增加
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "waterwall" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("waterwall");
    if( !cnd_data ) return;

    me->add_temp("apply/"+cnd_data["ability"], -cnd_data["add"] );   // 減少
}
