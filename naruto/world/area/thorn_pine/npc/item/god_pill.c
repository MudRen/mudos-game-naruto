#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�G����", ({ "twogod pill", "pill" }));
        set("unit", "��");
        set("base_value", 3600);
        set("base_weight", 10);
        set("food_stuff", 1);   // �����q�A���~�@�w�n�������q
        set("long", "��ɥR��O�P�믫���}�ġC\n");
        set("heal", ([ 
            "ap": 900,
            "hp": 900,
        ]));
    setup();
}

