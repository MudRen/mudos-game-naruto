#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("����", ({ "beef", "_CHILI_E_" }));
    if( !clonep() ) {
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 10);
        set("food_stuff", 10);
        set("long", "�n�Y�����סA�O�Ҩӷ��O�S���g���g�������C\n");
    }
    setup();
}
