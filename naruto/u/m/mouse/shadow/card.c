#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("殺手雇用卡", ({ "card", "_BANDIT_CARD_" }));
    if( !clonep() ) {
        set("base_unit", "張");
        set("unit", "張");
        set("base_value", 500000);
        set("base_weight", 100);
        set("long", "專門雇用殺手的卡，價格昂貴。");
    }
    setup();
}
