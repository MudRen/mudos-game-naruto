#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(HIG"���"NOR, ({ "celery", "_CHILI_A_" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 10);
        set("food_stuff", 10);
        set("no_sell", 1);
        set("long", "��⪺�C��A�D�_�Ӧ��دS�O�����D�C\n");
    }
    setup();
}
