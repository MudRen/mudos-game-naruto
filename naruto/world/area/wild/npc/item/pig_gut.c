#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"豬腸"NOR, ({ "pig's gut", "gut", "_PIG_GUT_" }));

    if( !clonep() ) {
        set("base_unit", "條");
        set("base_value", 10);
        set("base_weight", 600);
        set("food_stuff", 10);              // 食物量，食品一定要有食物量
        set("long", "一條血淋淋的豬腸。\n");
    }
    setup();
}
