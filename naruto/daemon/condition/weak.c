#include <ansi.h>
inherit CONDITION;

private void create()
{
    seteuid(getuid());
    DAEMON_D->register_condition_daemon("weak");
}

// 每 update 一次 消秏時效一點..
void condition_update(object me, string cnd, mixed cnd_data)
{
    if( !mapp(cnd_data) || (cnd_data["duration"]--) < 1 ) {
        me->delete_condition(cnd);
        tell_object(me, "你的虛弱消失了。\n");
        return;
    }
}

void condition_apply(object me, string cnd, mapping cnd_data)
{
    me->add_temp("apply/str", cnd_data["str"]);
    me->add_temp("apply/con", cnd_data["con"]);
    me->add_temp("apply/dex", cnd_data["dex"]);
    me->add_temp("apply/int", cnd_data["int"]);
    me->add_temp("apply/ap", cnd_data["ap"]);
    me->add_temp("apply/hp", cnd_data["hp"]);
    me->add_temp("apply/mp", cnd_data["mp"]);
    me->add_temp("apply/combat", cnd_data["combat"]);
    me->add_temp("apply/parry", cnd_data["parry"]);
    me->add_temp("apply/dodge", cnd_data["dodge"]);
    me->add_temp("apply/savage hit", cnd_data["savage hit"]);
    me->add_temp("apply/heavy hit", cnd_data["heavy hit"]);
    me->add_temp("apply/continual hit", cnd_data["continual hit"]);

    // 防止變成負的一直死掉
    if( me->query_stat("ap") <= 1 ) me->set_stat_current("ap", 1);
    if( me->query_stat("hp") <= 1 ) me->set_stat_current("hp", 1);
    if( me->query_stat("mp") <= 1 ) me->set_stat_current("mp", 1);
}

void condition_unapply(object me, string cnd, mapping cnd_data)
{
    me->add_temp("apply/str", -cnd_data["str"]);
    me->add_temp("apply/con", -cnd_data["con"]);
    me->add_temp("apply/dex", -cnd_data["dex"]);
    me->add_temp("apply/int", -cnd_data["int"]);
    me->add_temp("apply/ap", -cnd_data["ap"]);
    me->add_temp("apply/hp", -cnd_data["hp"]);
    me->add_temp("apply/mp", -cnd_data["mp"]);
    me->add_temp("apply/combat", -cnd_data["combat"]);
    me->add_temp("apply/parry", -cnd_data["parry"]);
    me->add_temp("apply/dodge", -cnd_data["dodge"]);
    me->add_temp("apply/savage hit", -cnd_data["savage hit"]);
    me->add_temp("apply/heavy hit", -cnd_data["heavy hit"]);
    me->add_temp("apply/continual hit", -cnd_data["continual hit"]);
    me->heal_stat("ap", me->query_stat_maximum("ap"));
    me->heal_stat("hp", me->query_stat_maximum("hp"));
    me->heal_stat("mp", me->query_stat_maximum("mp"));
}
