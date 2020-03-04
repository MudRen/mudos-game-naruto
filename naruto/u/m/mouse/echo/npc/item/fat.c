inherit F_FOOD;

void create()
{
    set_name("腦漿膏", ({ "brains fat", "fat" }));
    if( !clonep() ) {
        set("unit", "塊");
        set("base_unit", "塊");
        set("base_value", 100);            // 初期的藥，不需要太貴，讓玩家買得起
        set("base_weight", 10);
        set("food_stuff", 5);              // 食物量，食品一定要有食物量
        set("long", "一塊用鼠腦漿製成的膏，能夠加快精神回復。\n");
        set("condition", ([ "apheal2": ([ "duration": 15 ]) ]) );
    }
    setup();
}
