#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�G����", ({ "twoghost pill", "pill" }));
        set("unit", "��");
        set("base_value", 3600);
        set("base_weight", 10);
        set("food_stuff", 1);   // �����q�A���~�@�w�n�������q
        set("long", "��ɥR��O�P�]�O���}�ġC\n");
        set("heal", ([ 
            "mp": 900,
            "hp": 900,
        ]));
    setup();
}

