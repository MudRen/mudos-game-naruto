#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("彈夾", ({ "clip", "_CLIP_" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "個");
        set("value", 50);
        set("long", "用來更換子彈用的彈夾");
    }
    setup();
}
