#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(YEL"��G"NOR, ({ "Fruit", "fruit", "_TREE_FRUIT_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 200);
        set("food_stuff", 5);
        set("long", "��W���U�Ӫ��G��C\n");
    }
    setup();
}
