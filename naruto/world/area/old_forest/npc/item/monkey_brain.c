#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(RED"�U��"NOR, ({ "monkey brain", "brain", "_MONKEY_BRAIN_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 100);
        set("base_weight", 500);
        set("food_stuff", 20);
        set("long", "�U�l�����A�O�@�ثD�`���ת������C\n");
    }
    setup();
}
