#include <ansi.h>
inherit F_FOOD;
void create()
{
    set_name(RED"����"NOR, ({ "fish's lung", "lung" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 20);
        set("base_weight", 100);
        set("food_stuff", 5);
        set("long", "�@���{�䪺���͡C\n");
    }
    setup();
}
