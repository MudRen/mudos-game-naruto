#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIY"草帽"NOR, ({ "boater" }) );
    set_weight(1);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "頂");
        set("value", -1);
        set("no_box", 1);
        set("long", "某人送給魯夫的信物，對魯夫來說是非常重要的東西。\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "attack": 30,
        ]));

    }
    setup();
}
