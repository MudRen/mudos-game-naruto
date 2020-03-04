inherit F_FOOD;

void create()
{
    set_name("魔力丸", ({ "heal mp pill", "pill" }));
    set("unit", "顆");
    set("base_value", 600);
    set("base_weight", 10);
    set("food_stuff", 1);              // 食物量，食品一定要有食物量
    set("long", "吃了可以立即恢復你的魔力值(MP) 300 點。\n");
    set("heal", ([
        "mp": 300,
    ]) );
	setup();
}
