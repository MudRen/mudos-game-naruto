#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("魚肉", ({ "fish's meat", "meat" }));
    if( !clonep() ) {
        set("unit", "塊");
        set("base_unit", "塊");
        set("base_value", 10);
        set("base_weight", 100);
        set("food_stuff", 20);              // 食物量，食品一定要有食物量
        set("long", "海魚的肉類，含有豐富營養。\n");
    }
    setup();
}
