#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(YEL"�T�}"NOR, ({ "wolf's forward feet", "feet" }) );

    set_weight(2000);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long", "�@��T���e�}�A���A�i�H�˦��T�C\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 2,
        ]));
    }

    setup();
}
