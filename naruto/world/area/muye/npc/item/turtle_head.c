#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(GRN"龜頭"NOR, ({ "turtle's head", "head", "_TURTLE_HEAD_" }));
    if( !clonep() ) {
        set("food_stuff", 10);              // 食物量，食品一定要有食物量
        set("base_unit", "顆");
        set("base_value", 15);
        set("base_weight", 100);
        set("long", "一顆發出腥臭味的烏龜頭。\n");
    }
    setup();
}
