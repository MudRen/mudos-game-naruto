inherit F_FOOD;

void create()
{
    set_name("牙粉", ({ "tooth powder", "powder" }));
    if( !clonep() ) {
        set("unit", "包");
        set("base_unit", "包");
        set("base_value", 100);            // 初期的藥，不需要太貴，讓玩家買得起
        set("base_weight", 10);
        set("food_stuff", 5);              // 食物量，食品一定要有食物量
        set("long", "山狼虎牙所磨成的粉，能夠快速回復ＭＰ。\n");
        set("condition", ([ "mpheal2": ([ "duration": 15 ]) ]) );
    }
    setup();
}
