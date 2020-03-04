#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIY"神獸"RED"心臟"NOR, ({ "heart" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "顆");
        set("value", 0);
        set("no_box", 1);
        set("no_sell", 1);
        set("no_auc", 1);
        set("no_drop", 1);
        set("long", "暗紅色的心臟，跳動的速度非常緩慢，外表被一層白光包圍。");
    }
    setup();
}
