#include <ansi.h>
inherit F_FOOD;
void create()
{
    set_name(HIR"血丸"NOR, ({ "pill" }));
        if( !clonep() ) {
        set("unit", "盒");
        set("base_unit", "顆");
        set("base_value", 10);
        set("base_weight", 0);
        set("food_stuff", 5);        
        set("long", "一顆能起死回生的藥丸。\n");
        set("heal_mp", 9999);
        set("heal_ap", 9999);
        set("heal_hp", 9999);
        }
        setup();
}
