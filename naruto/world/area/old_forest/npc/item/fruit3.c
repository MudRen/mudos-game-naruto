#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(YEL"���G"NOR, ({ "Fruit", "fruit" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 200);
        set("food_stuff", 5);
        set("long", "���������G�C\n");
    }
    setup();
}
