// 滂沱大雨

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("rain");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIB"$N身旁的雲漸漸散去，雨也停止了。\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    mapping mcnd;
    
    if( !mapp(mcnd = me->query_condition(cnd)) ) mcnd = ([]);
    
    mcnd["duration"] = cnd_data["duration"];
    
    me->add_temp("apply/intimidate", -mcnd["intimidate"] ); // 減少攻擊技巧
    me->add_temp("apply/exact", -mcnd["exact"] );           // 減少命中能力
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "rain" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("rain");
    if( !cnd_data ) return;

    // 扣掉的要補回
    me->add_temp("apply/intimidate", cnd_data["intimidate"] );
    me->add_temp("apply/exact", cnd_data["exact"] );
}
