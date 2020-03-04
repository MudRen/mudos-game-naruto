inherit F_FOOD;

void create()
{
    set_name("二鬼丹", ({ "twoghost pill", "pill" }));
    if( !clonep() ) {
        set("unit", "顆");
        set("base_unit", "顆");
        set("base_value", 1500);
        set("base_weight", 10);
        set("food_stuff", 10);   // 食物量，食品一定要有食物量
        set("long", "能補充體力與ＭＰ的良藥。\n");
        set("condition", ([ 
            "mpheal4": ([ "duration": 15 ]),
            "hpheal4": ([ "duration": 15 ]),
        ]));
    }
    setup();
}
