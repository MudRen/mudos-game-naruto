#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"�T��"NOR, ({ "wolf's lung", "lung" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 600);
        set("food_stuff", 30);              // �����q�A���~�@�w�n�������q
        set("long", "�@����O�O���T�͡C\n");
    }
    setup();
}
