#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(GRN"綠色緊身褲"NOR, ({ "green pants", "pants" }) );

    set_weight(1500);
    setup_pants();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 8900);
        set("long", "一件深綠色的緊身褲，穿在身上你會感覺到一股熱血的氣息。\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 10,
            "dex": 3,
        ]));
    }

    setup();
}
