#include <ansi.h>

inherit ITEM;

int do_gie(object obj);

void create()
{
    set_name(HIK"棘"NOR, ({ "gie" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "包");
        set("value", 1000);
        set("long", "在地上會影響行動，直接丟人效果更好。可以丟(throw)");
    }
    setup();
}
void init()
{
    add_action("do_throw", "throw");
}
int do_throw(string arg)
{
    string func,target;
    object ob;
    if( this_player()->is_busy()) {
        write(CYN"你正在忙碌中。"NOR"\n");
        return 1;
    }
    if( !this_player()->is_fighting() ) {
        write(CYN"你沒在戰鬥。"NOR"\n");
        return 1;
    }
    if( !arg || sscanf(arg, "%s %s", func, target)!=2 )
        return notify_fail(CYN"你想用什麼丟誰？"NOR"\n");

    if( !objectp(ob = present(target, environment(this_player()))) )
        return notify_fail(CYN"你想用什麼丟誰？"NOR"\n");

    if( !ob ||
        !ob->is_character() ||
        ob->is_corpse() ||
        ob==this_player() )
        return notify_fail(CYN"你想用什麼丟誰？\n"NOR);

     if( userp(ob) ) return notify_fail("不能對玩家使用。\n");  // add by -Acme-
    if( func == "gie") {
        do_gie(ob);
        return 1;
    }
    return 0;
}
int do_gie(object ob)
{
    object me;
    me = this_player();
    message_vision("$N拿起"HIK"棘"NOR"快速丟向$n！\n"NOR, me, ob);
    if( random(ob->query_ability("evade")) > random(me->query_ability("exact")) ) {
        message_vision("        $n從旁邊避開了。\n", me, ob);
        destruct(this_object());
    }
    message_vision(HIK"        棘"NOR"掉了滿地，$n被限制了移動的路。\n"NOR, me, ob);
    ob->start_busy(1);
    destruct(this_object());
}
