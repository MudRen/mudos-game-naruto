#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(HIW"開襠褲"NOR, ({ "open pants", "pants" }) );
    set_weight(1500);
    setup_pants();
    if( !clonep() ) {
        set("unit", "條");
        set("value", 5400);
        set("long", "一條隨便補一補的破褲子，不過透氣度是無褲可比。\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 8,
            "int": 2,
        ]));
    }
    setup();
}
