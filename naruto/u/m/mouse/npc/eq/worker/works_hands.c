#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(HIB"["HIW"�դ�M"HIB"]"NOR, ({ "White Hands","hands" }) );

    set_weight(1500);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�զ�u���䪺�u�@�Τ�M�C\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "attack" : 10,
        ]));
    }

    setup();
}
