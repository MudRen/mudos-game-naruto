#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"�p����"NOR, ({ "chile", "_CHILI_B_" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 20);
        set("base_weight", 10);
        set("food_stuff", 50);
        set("no_sell", 1);
        set("long", "�ݰ_�Ӥp�p�����ԡA��꥿�O�������ٲĤ@���¤ѴԡC\n");
    }
    setup();
}
