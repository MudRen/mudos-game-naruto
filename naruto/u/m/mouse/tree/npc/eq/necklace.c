#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIM"果實"HIY"項鍊"NOR, ({ "fruit necklace", "necklace" }) );
    set_weight(900);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "串");
        set("value", 14000);
        set("long", "果實曬乾後做成的項鍊，由神木祝福後能保護配帶者。\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "hp": 100,
            "ap": 40,
        ]));
    }
    setup();
}
