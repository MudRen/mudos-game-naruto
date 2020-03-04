#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIR"公雞冠"NOR, ({ "cockscomb" }) );

    set_weight(3000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 3000);
        set("long", "一頂火紅的公雞冠，你想當雞？");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 8,
        ]));
    }

    setup();
}
