#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(YEL"【地之書】"NOR, ({ "earth book", "book" }));
    set_weight(1);
    if( !clonep() ) {
        set("middle_test", 2);
        set("unit", "個");
        set("value", 0);
        set("no_box", 1);
        set("long", "一個看似普通的卷軸，不知道有什麼用處。");
    }

    setup();
}
