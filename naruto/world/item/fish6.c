#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�j��", ({ "abalone", "_ABALONE_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 200);
        set("base_weight", 100);
        set("food_stuff", 10);              // �����q�A���~�@�w�n�������q
        set("long", "�@���a�۸{������j���C\n");
    }
    setup();
}
