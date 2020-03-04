inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(HIY"蜂蜜"NOR, ({ "honey" }));
        if( !clonep() ) {
                set("unit", "堆");
                set("base_unit", "口");
                set("base_value", 10);             // 初期的藥，不需要太貴，讓玩家買得起
                set("base_weight", 10);
                set("food_stuff", 5);              // 食物量，食品一定要有食物量
                set("long", "一口甜甜蜂蜜，遠遠看到螞蟻聞香而來。\n");
                set("condition", ([ "hpheal1": ([ "duration": 10 ]) ]) );
        }
        setup();
}

