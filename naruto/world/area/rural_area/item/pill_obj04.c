#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"小辣椒"NOR, ({ "chile", "_CHILI_B_" }));
    if( !clonep() ) {
        set("unit", "條");
        set("base_unit", "條");
        set("base_value", 20);
        set("base_weight", 10);
        set("food_stuff", 50);
        set("no_sell", 1);
        set("long", "看起來小小的辣椒，其實正是辣味號稱第一的朝天椒。\n");
    }
    setup();
}
