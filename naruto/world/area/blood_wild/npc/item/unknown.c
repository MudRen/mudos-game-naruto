#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("廢物", ({ "unknown" }));
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "把");
        set("value", 0);
        set("long", "這是一個沒有用的廢棄物。");
    }
    setup();
}
