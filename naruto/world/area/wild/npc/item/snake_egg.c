#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�D�J", ({ "snake's egg", "egg", "_SNAKE_EGG_" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 100);
        set("base_weight", 600);
        set("food_stuff", 10);              // �����q�A���~�@�w�n�������q
        set("long", "�@���u���i����j�p���D�J�C\n");
    }
    setup();
}
