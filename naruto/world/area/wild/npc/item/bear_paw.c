#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(HIK"���x"NOR, ({ "bear's paw", "paw", "_BEAR_PAW_" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 200);
        set("base_weight", 600);
        set("food_stuff", 50);              // �����q�A���~�@�w�n�������q
        set("long", "�@�Ӧ�O�O�����x�C\n");
        set("level_d1", 1);
    }
    setup();
}
