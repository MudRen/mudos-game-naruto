#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("【大神的權力】", ({ "The admin power", "power" }));

    set_weight(1);

    if( !clonep() ) {
        set("unit", "股");
        set("value", 0);
        set("long", 
"這是創造這個世界的大神的力量所在。只要您擁有這個東西，\n"
"即等於擁有全宇宙無與論比的力量！！"
);
    }
    setup();

}

