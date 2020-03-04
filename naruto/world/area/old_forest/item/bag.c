#include <login.h>
#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("材料包", ({ "bag", "_WP_BAG_" }));
    set_weight(3);
    if( !clonep() ) {
        set("unit", "大包");
        set("value", 1);
        set("no_box", 1);
        set("no_auc", 1);
        set("long", "裝的滿滿的材料包，不過密封的很緊不知道裡面都是什麼東西。");
    }
    setup();
}
