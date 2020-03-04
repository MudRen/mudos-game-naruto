#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(HIB"["HIW"白手套"HIB"]"NOR, ({ "White Hands","hands" }) );

    set_weight(1500);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 10);
        set("long", "白色滾藍邊的工作用手套。\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "attack" : 10,
        ]));
    }

    setup();
}
