// 細胞活化

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("ca2");
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
    
    me->add_temp("apply/str", mcnd["str"] );          // 增加力量
    me->add_temp("apply/dex", mcnd["dex"] );          // 增加敏捷
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "ca2" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("ca2");
    if( !cnd_data ) return;

    me->add_temp("apply/str", -cnd_data["str"] );
    me->add_temp("apply/dex", -cnd_data["dex"] );
}
