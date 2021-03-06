#include <ansi.h>
inherit F_FOOD;

void create()
{
	set_name("豚骨拉麵", ({ "noodles" }));
	set("unit", "碗");
	set("base_value", 300);
	set("base_weight", 200);
	set("food_stuff", 50);              // 食物量，食品一定要有食物量
	set("long", "這是旋渦鳴人最常吃的【一樂】豚骨拉麵，白濁的豚骨汁，汁濃而且\n"
                "有點黏黏的，這就是用豬骨以大火長時間熬煮出的乳白色濃湯，加上\n"
                "蔥、蒜、麻油調味的湯頭，許多的配料以及咬勁十足的細麵，濃厚的\n"
                "口味令人讚不絕口，便宜的價格、豐富的配料、風味絕佳的湯頭，絕\n"
                "對是一碗讓你吃了還想再吃的好麵！\n"
                "三十秒內恢復 300 點精力值、體力值、魔力值。\n" );
    set("condition", ([
	    "food": ([
	        "name": HIG"進食中"NOR,
	        "heal_ap": 20,
	        "heal_hp": 20,
	        "heal_mp": 20,
	        "duration": 15,
	    ]),
	]) );
	setup();
}
