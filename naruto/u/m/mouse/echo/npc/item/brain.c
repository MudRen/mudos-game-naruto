#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"����"NOR, ({ "mouse brain", "brain", "_MOUSE_HEAD_" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 100);
        set("base_weight", 600);
        set("food_stuff", 10);              // �����q�A���~�@�w�n�������q
        set("long", "�@�ά��⪺�a�����U�C\n");
    }
    setup();
}
