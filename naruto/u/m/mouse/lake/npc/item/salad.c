#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIR"�s���F��"NOR, ({ "salad" }));
    if( !clonep() ) {
        set("base_unit", "�L");
        set("unit", "�L");
        set("base_value", 100);
        set("base_weight", 500);
        set("food_stuff", 20);
        set("long", "�s�A���s���f�t���a���F�ԡA������Q�`�������H�߷R�C\n");
    }
    setup();
}
