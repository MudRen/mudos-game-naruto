#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name(BBLU+HIC"B級制式手環"NOR, ({ "blevel wrist", "wrist" }) );
    set_weight(300);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "個");
        set("value", 2000);
        set("long", "B級NPC的制式手環，有不錯的防禦能力。\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "armor": 4,
            ]));
    }

    setup();
}

