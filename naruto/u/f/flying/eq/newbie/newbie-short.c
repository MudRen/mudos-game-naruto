#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name("新手短褲", ({ "newbie short", "short" }) );
    set_weight(200);
    setup_pants();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 10);
        set("long", "新手短褲，看上去沒比尿包好上多少。\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 1,
        ]));
    }

    setup();
}

