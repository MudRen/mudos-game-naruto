#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(YEL"�U�x"NOR, ({ "monkey hand", "hand" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 20);
        set("base_weight", 600);
        set("food_stuff", 10);
        set("long", "�U�l��x�A�`�Q���˹��Ϋ~�C\n");
    }
    setup();
}
