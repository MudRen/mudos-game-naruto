#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"�D�x"NOR, ({ "snake's gall", "gall", "_SNAKE_GALL_" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 200);
        set("base_weight", 600);
        set("food_stuff", 5);              // �����q�A���~�@�w�n�������q
        set("long", "�@�ɸ{����Q�����D�x�C\n");
    }
    setup();
}
