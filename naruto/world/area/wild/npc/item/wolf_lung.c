#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"狼肺"NOR, ({ "wolf's lung", "lung" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("base_value", 10);
        set("base_weight", 600);
        set("food_stuff", 30);              // 食物量，食品一定要有食物量
        set("long", "一顆血淋淋的狼肺。\n");
    }
    setup();
}
