#include <ansi.h>
inherit F_FOOD;

void create()
{
	set_name("中饅頭", ({ "middle manto", "manto" }));
    set("unit", "顆");
	set("base_value", 100);
	set("base_weight", 100);
	set("food_stuff", 20);              // 食物量，食品一定要有食物量
	set("long",
	    "一顆饅頭，在進食的過程中，可以恢復你的體力值(HP)。\n"
	    "三十秒內恢復 300 點體力值。\n"
	);
	set("condition", ([
	    "food": ([
	        "name": HIG"進食中"NOR,
	        "heal_hp": 20, 
	        "duration": 15,
	    ]),
	]) );
	setup();
}
