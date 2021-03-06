#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"防風鏡"NOR, ({ "windbreak hat", "hat" }) );

    set_weight(1000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 300);
        set("long", "一頂上頭附有防風鏡的帽子，一副很新潮的模樣。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 3,
        ]));
    }

    setup();
}
