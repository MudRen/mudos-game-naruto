#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("����", ({ "chicken", "_KARE_D_" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 10);
        set("food_stuff", 10);
        set("long", "�n�Y�����סA�S���������E���ìV�C\n");
    }
    setup();
}
