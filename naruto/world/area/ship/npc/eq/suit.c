#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIB"潛水衣"NOR, ({ "diving suit", "suit" }) );
    set_weight(6000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "件");
        set("value", 6750);
        set("long", "緊身的潛水裝，背後有擺放氧氣筒的地方，腿上可以綁鉛塊。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
            "exact": 5,
            "ap": 100,
        ]));
    }
    setup();
}
