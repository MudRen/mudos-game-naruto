#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("章魚", ({ "octopus" }));
    if( !clonep() ) {
        set("base_unit", "隻");
        set("unit", "隻");
        set("base_value", 40);
        set("base_weight", 100);
        set("food_stuff", 30);              // 食物量，食品一定要有食物量
        set("long", "海洋生物，使用吸盤式移動。章魚是種很聰明的生物，平常會以保護\n"
                    "色隱藏自己。八隻腳是牠的特徵。\n");
    }
    setup();
}
