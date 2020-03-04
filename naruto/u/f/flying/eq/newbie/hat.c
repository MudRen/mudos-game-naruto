#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name("新手帽", ({ "newbie hat", "hat" }) );

    set_weight(300);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 10);
        set("long", "一頂小小的新手帽，上面有破洞。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 1,
            "exact": 1,
        ]));
    }

    setup();
}

