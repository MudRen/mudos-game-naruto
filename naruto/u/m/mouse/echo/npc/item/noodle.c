inherit F_FOOD;

void create()
{
    set_name("牛肉麵", ({ "noodles", "_BEEF_NOODLES_" }));
    if( !clonep() ) {
        set("unit", "碗");
        set("base_unit", "碗");
        set("base_value", 500);
        set("base_weight", 10);
        set("food_stuff", 30);
        set("long", @LONG
由賣麵的老張所做的上等牛肉麵，所用的原料是上等牛肉，大骨頭和
多種蔬菜所熬成的美味湯頭，麵條香Ｑ有勁，搭配有少許牛筋的爽口
牛肉，吃完之後再一喝湯，馬上將剛才所嘗的美味又一次的灌入口中
，讓人回味無窮，讚不絕口。
【吃一次得15點時效的Ｂ級提神術、Ｂ級天地術以及Ｂ級還陽術。】
LONG);
        set("condition", ([ "apheal2": ([ "duration": 15 ]),
                            "hpheal2": ([ "duration": 15 ]),
                            "mpheal2": ([ "duration": 15 ]),
                         ]));
    }
    setup();
}
