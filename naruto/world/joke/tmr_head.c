#include <ansi.h>

inherit ITEM;

void create()
{
      set_name(HIC"奇"NOR"大無比的"HIG"巨神龍炮"NOR, ({ "tmr's dragon head", "head" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "顆");
        set("value", 0);
        set("long", "一顆小小的而且長得很奇怪的頭");
    }
    setup();

}
