#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIR"輝夜之證"NOR, ({ "paper", "__WHEYA__" }));
    set_weight(1);
    if( !clonep() ) {
        set("unit", "張");
        set("value", 0);
        set("long", "大蛇丸交給竹取一族的通行證明。");
    }
    setup();
}
