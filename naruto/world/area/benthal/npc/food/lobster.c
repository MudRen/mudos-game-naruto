#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("龍蝦", ({ "lobster" }));
    if( !clonep() ) {
        set("unit", "隻");
        set("base_unit", "隻");
        set("base_value", 300);
        set("base_weight", 100);
        set("food_stuff", 50);              // 食物量，食品一定要有食物量
        set("long","龍蝦是饕客所鍾情的海上鮮品，愛牠的鮮甜、滑嫩，以及變化萬千的\n"
                   "食法。只要變化配搭材料，就能讓食客感受海鮮的新味道。\n");
    }
    setup();
}
