#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"���}"NOR, ({ "mouse's foot", "foot" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 100);
        set("food_stuff", 15);              // �����q�A���~�@�w�n�������q
        set("long", "�@���O�O���ѹ��}�C\n");
    }
    setup();
}
