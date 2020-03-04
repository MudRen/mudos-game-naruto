#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIK"心"HIW"魂"NOR, ({ "heart soul", "soul" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "顆");
        set("value", 2);
        set("no_box", 1);
        set("no_sell", 1);
        set("no_auc", 1);
        set("no_drop", 1);
        set("long", "心中的魂魄，黯淡無光，卻隱約地閃著一種希望。");
    }
    setup();
}
