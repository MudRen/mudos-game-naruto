#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"鼠腳"NOR, ({ "mouse's foot", "foot" }));
    if( !clonep() ) {
        set("base_unit", "支");
        set("base_value", 10);
        set("base_weight", 100);
        set("food_stuff", 15);              // 食物量，食品一定要有食物量
        set("long", "一支血淋淋的老鼠腳。\n");
    }
    setup();
}
