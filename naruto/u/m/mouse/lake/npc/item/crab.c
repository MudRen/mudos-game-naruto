#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIR"�ɦץլ�"NOR, ({ "crab cook","crab" }));
    if( !clonep() ) {
        set("base_unit", "�|");
        set("unit", "�|");
        set("base_value", 100);
        set("base_weight", 500);
        set("food_stuff", 20);
        set("long", "�ɦ׸g�Ѳ���p���C���A��K���A�������C\n");
    }
    setup();
}
