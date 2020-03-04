#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"龍"HIW"魂"NOR, ({ "dragon soul", "soul" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "顆");
        set("value", 2);
        set("no_box", 1);
        set("no_sell", 1);
        set("no_drop", 1);
        set("long", "龍的魂魄，龍氣在魂魄外側形成一道保護膜，非常奇特。");
    }
    setup();
}
