#include <ansi.h>
#include <armor.h>
inherit F_WRIST_EQ;
void create()
{
    set_name(BRED+HIR"血繼守護"NOR, ({ "blood wrist", "wrist" }) );
    set_weight(100);
    setup_wrist_eq();
    if( !clonep() ) {
        set("unit", "個");
        set("value", 0);
        set("long", "具有神秘功效的護手\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,
        ]));
        set("wear_msg",RED"$N戴上"+name()+RED"的同時，瞬間一道紅光射入$N的體內！\n"NOR);
    }

    setup();
}

