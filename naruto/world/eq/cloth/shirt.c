#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("汗衫", ({ "shirt" }) );

    set_weight(800);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 500);
        set("long", "一件很容易吸汗的汗衫。\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 2,
            "evade": 2,
        ]));
    }
    setup();
}

