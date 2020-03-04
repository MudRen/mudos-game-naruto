#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;
void create()
{
    set_name(BRED+HIR"血繼力護"NOR, ({ "blood fist", "fist" }) );
    set_weight(100);
    setup_hand_eq();
    if( !clonep() ) {
        set("unit", "雙");
        set("value", 0);
        set("long", "具有神秘功效的拳套\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,
            "attack": 100,            
        ]));
        set("wear_msg",RED+"$N穿上"+name()+RED"的同時，天上降下數道紅光圍繞著$N！\n"NOR);
    }

    setup();
}

