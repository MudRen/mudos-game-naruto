#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�G��", ({ "jelly" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 20);
        set("base_weight", 100);
        set("food_stuff", 10);
        set("long", "�@���o�䪺�ªG��...�ִ��Y�C\n");
    }
    setup();
}
