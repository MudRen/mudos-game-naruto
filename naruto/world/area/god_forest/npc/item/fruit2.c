#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIC"����"HIW"�G"NOR"", ({ "hp fruit", "fruit" }));
    set("unit", "��");
    set("base_value", 0);
    set("no_box", 1);
    set("base_weight", 10);
    set("food_stuff", 10);
    set("long", "�Y�F�i�H�ߧY��_�A����O��(HP) 1500 �I�C\n");
    set("heal", ([
        "hp": 1500,
    ]) );
    setup();
}
