#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("dp");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        tell_object(me, "你的倍化術消失了。\n");
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    me->add_temp("apply/hp", cnd_data["hp"] );                  // 增加血量
    me->add_temp("apply/attack", cnd_data["attack"] );          // 增加攻擊力
    me->add_temp("apply/armor", cnd_data["armor"] );            // 增加防禦力
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    me->add_temp("apply/hp", -cnd_data["hp"] );
    me->add_temp("apply/attack", -cnd_data["attack"] );
    me->add_temp("apply/armor", -cnd_data["armor"] );

    if( me->query_stat("hp") > me->query_stat_maximum("hp") ) me->set_stat_current("hp", me->query_stat_maximum("hp"));
}
