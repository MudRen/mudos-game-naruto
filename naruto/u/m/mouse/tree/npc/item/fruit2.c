#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIM"���G"NOR, ({ "Fruit", "fruit", "_WATER_FRUIT_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 20);
        set("base_weight", 200);
        set("food_stuff", 5);
        set("long", "��W���������G�C\n");
    }
    setup();
}
