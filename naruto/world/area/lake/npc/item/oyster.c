#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIW"生蠔"NOR, ({ "Paciffic oyster","oyster" , "_OYSTER_"}));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("unit", "顆");
        set("base_value", 150);
        set("base_weight", 500);
        set("food_stuff", 20);
        set("long", "大顆的蚵，味道香甜鮮美，適合生食，價格昂貴。\n");
    }
    setup();
}
