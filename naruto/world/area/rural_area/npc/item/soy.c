#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"醬油"NOR, ({ "soy", "_PILL_SOY_" }));
    if( !clonep() ) {
        set("unit", "瓶");
        set("value", 500);
        set("base_value", 500);
        set("base_weight", 20);
        set("long","上面寫著《鱉甲萬》甘純醬油，好像有哪裡不太對？\n");
    }
    setup();
}
