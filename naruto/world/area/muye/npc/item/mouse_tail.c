#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"鼠尾"NOR, ({ "mouse's tail", "tail" }));
    if( !clonep() ) {
        set("base_unit", "根");
        set("base_value", 10);
        set("base_weight", 100);
        set("food_stuff", 10);              // 食物量，食品一定要有食物量
        set("long", "一根血淋淋的老鼠尾巴。\n");
    }
    setup();
}
