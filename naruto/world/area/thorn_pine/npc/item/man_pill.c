#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�G�H��", ({ "twoman pill", "pill" }));
        set("unit", "��");
        set("base_value", 3600);
        set("base_weight", 10);
        set("food_stuff", 1);   // �����q�A���~�@�w�n�������q
        set("long", "��ɥR�믫�P�]�O���}�ġC\n");
        set("heal", ([
            "ap": 900,
            "mp": 900,
        ]));
    setup();
}
