inherit F_FOOD;

void create()
{
        set_name("新手兵糧丸", ({ "newbie pill" ,"pill"}));
        if( !clonep() ) {
                set("unit", "堆");
                set("base_unit", "粒");
                set("base_value", 10);             // 初期的藥，不需要太貴，讓玩家買得起
                set("base_weight", 10);
                set("food_stuff", 20);              // 食物量，食品一定要有食物量
                set("long", "一粒新手兵糧丸。\n"
                    "【吃一次得50點時效的Ｃ級提神術以及Ｃ級還陽術。】\n");
                set("condition", ([ "apheal1": ([ "duration": 50 ]),
                                        "hpheal1": ([ "duration": 50 ]),
                                        ]));
        }
        setup();
}


