// 借貸券

#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("ticket");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        message_vision(HIW"$N無法像之前那麼專注了。\n"NOR, me);
        me->delete_condition(cnd);
        return;
    }
}

// 用狀態消失去判斷刪除會比較保險
void condition_unapply(object me, string cnd, mapping cnd_data)
{
    if( cnd != "ticket" ) return;
    if( !cnd_data ) cnd_data = me->query_condition("ticket");
    if( !cnd_data ) return;

    me->delete_temp("ticket_card/"+cnd_data["ability"]);
    // 如果有借貸券裡技的特殊效果，在借貸券失效時也同時失去效果
    if( me->query_condition("waterwall", 1) != 0) {
        write("因為借貸券的效果結束，連帶著其他功能也失去效用了。\n");
        me->delete_condition("waterwall");
    }
}
