#include <ansi.h>
inherit F_FOOD;
void create()
{
    set_name(RED"狼心"NOR, ({ "wolf's heart", "heart" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("base_value", 10);
        set("base_weight", 600);
        set("food_stuff", 20);              // 食物量，食品一定要有食物量
        set("long", "一顆血淋淋的狼心。\n");
    }
    setup();
}
