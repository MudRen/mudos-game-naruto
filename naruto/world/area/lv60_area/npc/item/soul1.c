#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIG"妖"HIW"魂"NOR, ({ "lich soul", "soul" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "顆");
        set("value", 2);
        set("no_box", 1);
        set("no_sell", 1);
        set("no_drop", 1);
        set("long", "妖魔的魂魄，所發出的亮光詭異動人，吸引你的目光。");
    }
    setup();
}
