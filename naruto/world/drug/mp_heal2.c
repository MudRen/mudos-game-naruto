inherit F_FOOD;

void create()
{
    set_name("大魔力丸", ({ "big heal mp pill", "pill" }));
	set("unit", "顆");
    set("base_value", 1800);
	set("base_weight", 10);
	set("food_stuff", 1);              // 食物量，食品一定要有食物量
    set("long", "吃了可以立即恢復你的魔力值(MP) 900 點。\n");
    set("heal", ([
        "mp": 900,
    ]) );
	setup();
}
