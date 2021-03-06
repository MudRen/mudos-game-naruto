#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(GRN"綠色緊身衣"NOR, ({ "green cloth", "cloth" }) );

    set_weight(1200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 8900);
        set("long", "一件深綠色的緊身衣，穿在身上你會感覺到一股熱血的氣息。\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 10,
            "dex": 3,
        ]));
    }
    setup();
}