inherit F_FOOD;
void create()
{
    set_name("超級大補丸", ({ "super ap pill", "pill" }));
        set("unit", "顆");
    set("base_value", 999999);
        set("base_weight", 10);
        set("food_stuff", 1);                            // 食物量，食品一定要有食物量
    set("long", "吃了可以立即恢復你的精力值(AP) 9999 點。\n");
    set("heal", ([
        "ap": 9999,
        ]) );
        setup();
}

