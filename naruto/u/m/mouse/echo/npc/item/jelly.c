inherit F_FOOD;

void create()
{
    set_name("蛋白凍", ({ "albumin jelly", "jelly" }));
    if( !clonep() ) {
        set("unit", "塊");
        set("base_unit", "塊");
        set("base_value", 100);            // 初期的藥，不需要太貴，讓玩家買得起
        set("base_weight", 10);
        set("food_stuff", 5);              // 食物量，食品一定要有食物量
        set("long", "一塊用蛇蛋白製成的果凍，能夠加快體力回復。\n");
        set("condition", ([ "hpheal2": ([ "duration": 15 ]) ]) );
    }
    setup();
}
