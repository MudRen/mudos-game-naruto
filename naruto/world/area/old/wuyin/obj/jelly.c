inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(HIY"果凍"NOR, ({ "jelly" }));
        if( !clonep() ) {
                set("unit", "堆");
                set("base_unit", "粒");
                set("base_value", 10);             // 初期的藥，不需要太貴，讓玩家買得起
                set("base_weight", 10);
                set("food_stuff", 5);              // 食物量，食品一定要有食物量
                set("long", "一粒軟趴趴的果凍。\n");
                set("condition", ([ "apheal1": ([ "duration": 10 ]) ]) );
        }
        setup();
}
