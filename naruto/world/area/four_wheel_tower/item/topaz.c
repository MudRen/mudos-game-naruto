#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BYEL+HIY"黃玉"NOR, ({ "topaz" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("unit", "顆");
        set("base_value", 20000);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "金黃色的玉，是商人們最喜歡的玉石，因為在光芒下金光閃閃顯得很\n"
                    "有派頭，除了能夠展現商人的氣勢，也能夠增加物品的買氣。");
    }
    setup();
}