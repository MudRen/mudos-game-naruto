#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(HIY"魚肝油"NOR, ({ "cod liver oil", "oil" }));
    if( !clonep() ) {
        set("unit", "顆");
        set("base_unit", "顆");
        set("base_value", 100);
        set("base_weight", 100);
        set("food_stuff", 50);              // 食物量，食品一定要有食物量
        set("long", "用魚的內臟所製成的健康食品。\n");
    }
    setup();
}
