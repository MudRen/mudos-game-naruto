#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(HIW"絲質手套"NOR, ({ "spider gloves","gloves" }) );

    set_weight(1200);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 4500);
        set("long", "一雙質料非常好的絲質手套，應該是某種珍貴的蜘蛛絲。\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 3,
            "hp": 50,
        ]));
    }

    setup();
}

