inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(YEL"章魚燒"NOR, ({ "taco burn","taco","burn" }));
        if( !clonep() ) {
                set("unit", "堆");
                set("base_unit", "串");
                set("base_value", 70);             // 初期的藥，不需要太貴，讓玩家買得起
                set("base_weight", 10);
                set("food_stuff", 5);              // 食物量，食品一定要有食物量
                set("long", "一串香噴噴的章魚丸子，每個丸子上都有章魚喜怒愛樂的圖案，熱呼呼的○●○●-。\n");
                set("condition", ([ "hpheal2": ([ "duration": 8 ]) ]) );
        }
        setup();
}
