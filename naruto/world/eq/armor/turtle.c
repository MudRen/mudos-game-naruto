#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(GRN"龜甲"NOR, ({ "turtle armor", "armor" }) );

    set_weight(6000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 1000);
        set("long", "一件龜殼甲，防禦能力不錯，但是很笨重且穿起來就像烏龜。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
        ]));
    }

    setup();
}

