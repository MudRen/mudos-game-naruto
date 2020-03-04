#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("念查急救", ({ "mp help", "help" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "包");
        set("value", 4000);
        set("long", "戰鬥中急救專用，以(use)使用。");
    }
    setup();
}
void do_use(object me)
{
    if( !this_player()->is_fighting() ) {
        write(CYN"沒在戰鬥吃什麼急救包。"NOR"\n");
        return;
    }
    if( me->query_stat_current("mp") > me->query_stat_maximum("mp")/4 ) {
        write(CYN"只有在魔力不足時才能使用急救包。"NOR"\n");
        return;
    }
    message_vision("$N打開$n將裡面的藥品快速吞了下去。好像回復少許ＭＰ\n", me, this_object());
    me->heal_stat("mp", 1500);
    destruct(this_object());
}
