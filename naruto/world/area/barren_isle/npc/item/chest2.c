#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"《紅寶箱》"NOR, ({ "red chest", "chest" }));
    set_weight(1);
    if( !clonep() ) {
        set("piece_test", 1);
        set("unit", "個");
        set("no_box", 1);
        set("value", 0);
        set("long", "裡面空空的紅色寶箱，似乎沒什麼價值。");
    }
    setup();
}
