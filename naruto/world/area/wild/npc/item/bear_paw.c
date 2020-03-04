#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(HIK"熊掌"NOR, ({ "bear's paw", "paw", "_BEAR_PAW_" }));

    if( !clonep() ) {
        set("base_unit", "個");
        set("base_value", 200);
        set("base_weight", 600);
        set("food_stuff", 50);              // 食物量，食品一定要有食物量
        set("long", "一個血淋淋的熊掌。\n");
        set("level_d1", 1);
    }
    setup();
}
