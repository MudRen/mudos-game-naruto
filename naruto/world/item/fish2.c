#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("���N��", ({ "lu jie fish", "fish", "_HOLENSO_C_" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 20);
        set("base_weight", 100);
        set("food_stuff", 15);              // �����q�A���~�@�w�n�������q
        set("long", "�@�����o�_�ΩǪ������C\n");
    }
    setup();
}
