#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"糯米"NOR, ({ "wafer", "_KARE_B_" }));
    if( !clonep() ) {
        set("unit", "袋");
        set("value", 300);
        set("base_value", 300);
        set("base_weight", 10);
        set("long","比一般的米更具粘性，適合用來做米丸子之類的食物。\n");
    }
    setup();
}
