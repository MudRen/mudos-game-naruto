#include <ansi.h>
#include <armor.h>
inherit F_HEAD_EQ;

void create()
{
    set_name(HIG"椰子殼"NOR, ({ "coconut shell", "shell" }) );
    set_weight(1500);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "頂");
        set("value", 100);
        set("long", "椰子的外皮，非常堅硬。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 2,
        ]));
    }
    setup();
}
