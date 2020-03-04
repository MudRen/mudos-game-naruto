#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name("海軍西裝長褲", ({ "lounge pants", "pants" }) );

    set_weight(1200);

    setup_pants();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 22500);
        set("long", "海軍的標準服裝，由身份較高的海軍人員所穿著。\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 15,
        ]));
    }
    setup();
}
