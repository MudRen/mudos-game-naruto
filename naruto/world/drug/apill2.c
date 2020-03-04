#include <ansi.h>
	
inherit F_FOOD;

void create()
{
	set_name("中杯雞精", ({ "middle essence of chicken", "essence", "chicken" }));
    set("unit", "杯");
	set("base_value", 100);
	set("base_weight", 100);
	set("food_stuff", 20);              // 食物量，食品一定要有食物量
	set("long",
	    "一杯雞精，在進食的過程中，可以恢復你的精力值(AP)。\n"
	    "三十秒內恢復 300 點精力值。\n"
	);
	set("condition", ([
	    "food": ([
	        "name": HIG"進食中"NOR,
	        "heal_ap": 20, 
	        "duration": 15,
	    ]),
	]) );
	setup();
}
