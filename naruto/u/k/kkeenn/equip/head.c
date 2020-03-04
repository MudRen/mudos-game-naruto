#include <ansi.h>
#include <armor.h>
inherit F_HEAD_EQ;
void create()
{
    set_name(BRED+HIR"血繼靈護"NOR, ({ "blood helmet", "helmet" }) );
    set_weight(100);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "個");
        set("value", 0);
        set("long", "具有神秘功效的護額\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 30,
            "exact": 30,
        ]));
        set("wear_msg",RED"$N戴上"+name()+RED"的同時，$N的雙眼瞬間變成血紅！\n"NOR);
    }

    setup();
}

