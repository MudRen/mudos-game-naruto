#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("���x", ({ "urchin" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 20);
        set("base_weight", 100);
        set("food_stuff", 15);              // �����q�A���~�@�w�n�������q
        set("long", "�~�֦��몺���v�ͪ��A�̭��׽�ƹ��A���C\n");
    }
    setup();
}
