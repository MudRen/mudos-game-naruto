#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name("蟹黃生蠔鮑魚龜頭水果拉麵", ({ "noodles", "_GOOD_FOOD_" }));
                set("unit", "堆");
                set("base_unit", "碗");
                set("base_value", 600);
                set("base_weight", 250);
                set("food_stuff", 60);              // 食物量，食品一定要有食物量
    set("no_box", 1);
                set("long", "這是一碗一樂拉麵館老闆特製的拉麵。\n"
                    "三十秒內恢復 300 點精力值、體力值、魔力值。\n");
set("condition", ([
    "food": ([
        "name": HIG"進食中"NOR,
        "heal_ap": 40,
        "heal_hp": 40,
        "heal_mp": 40,
        "duration": 15,
    ]),
]) );
        setup();
}
