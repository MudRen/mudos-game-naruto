#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("雞肉", ({ "chicken", "_KARE_D_" }));
    if( !clonep() ) {
        set("unit", "塊");
        set("base_unit", "塊");
        set("base_value", 10);
        set("base_weight", 10);
        set("food_stuff", 10);
        set("long", "好吃的雞肉，沒有受到雞瘟的污染。\n");
    }
    setup();
}
