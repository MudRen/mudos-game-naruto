#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name("新手手環", ({ "newbie wrist", "wrist" }) );
    set_weight(10);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "個");
        set("value", 10);
        set("long", "將飲料上的條碼私下來，在手上貼成一圈。\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "armor": 1,
            ]));
    }

    setup();
}


