#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�F��", ({ "clam" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 20);
        set("base_weight", 100);
        set("food_stuff", 15);              // �����q�A���~�@�w�n�������q
        set("long", "�H�B�i�����������ߥͪ��C\n");
    }
    setup();
}
