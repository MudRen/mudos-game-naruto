#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"����"NOR, ({ "mouse's tail", "tail" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 100);
        set("food_stuff", 10);              // �����q�A���~�@�w�n�������q
        set("long", "�@�ڦ�O�O���ѹ����ڡC\n");
    }
    setup();
}
