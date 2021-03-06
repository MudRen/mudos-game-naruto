#include <ansi.h>

inherit ITEM;

int do_dart(object obj);

void create()
{
    set_name("飛鏢", ({ "dart" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "支");
        set("value", 100);
        set("long", "忍者常用的飛鏢。可以丟(throw)");
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
    if( func == "dart") {
        do_dart(ob);
        return 1;
    }
    return 0;
}
int do_dart(object ob)
{
    object me;
    int damage;
    me = this_player();
    damage = (me->query_ability("attack") - ob->query_ability("defend"))/2;
    damage -= random(50);
    message_vision("$N拿起飛鏢快速丟向$n！\n"NOR, me, ob);
    if( (damage <= 0 ) || (random(ob->query_ability("evade")) > random(me->query_ability("exact"))) ) {
        message_vision("        $n從旁邊避開了。(0)\n", me, ob);
        destruct(this_object());
    }
    message_vision("        「噗」地一聲，飛標在$n身上造成一點傷害("+damage+")\n"NOR, me, ob);
    ob->damage_stat("hp", damage, ob);
    destruct(this_object());
}
