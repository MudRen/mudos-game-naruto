#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIM"���G��"NOR, ({ "Fruit", "fruit", "_KING_FRUIT_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 200);
        set("base_weight", 500);
        set("food_stuff", 20);
        set("long", "�j�������G�A�����n�Y�C\n");
    }
    setup();
}
