#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("半獸人擋路小子", ({ "orc man", "man" }) );
    set_level(1);
    set_race("human");
    set("age", 12);
    set("no_fight", 1);
    set("long", "雖然稚氣未脫卻有一種野性的感覺，看起來普普通通的半獸人小子。\n");
    set("guard_exit", ({ "south", "southwest", "southeast" })); // 守著出口
    setup();
}
int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n擋住了$N的去路。\n"NOR, this_player(), this_object());
    do_chat((: command, "say 碎骨寨還在整修中，目前暫不開放。"NOR:));
    return 1;
}
