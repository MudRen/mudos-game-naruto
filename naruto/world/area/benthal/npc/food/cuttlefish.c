#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("烏賊", ({ "cuttlefish" }));
    if( !clonep() ) {
        set("unit", "隻");
        set("base_unit", "隻");
        set("base_value", 40);
        set("base_weight", 100);
        set("food_stuff", 30);              // 食物量，食品一定要有食物量
        set("long", "海洋生物，味道鮮美，特色是牠的移動方式是噴射式移動。當遇到危\n"
                    "險時會噴出「墨汁」然後逃命。\n");
    }
    setup();
}
