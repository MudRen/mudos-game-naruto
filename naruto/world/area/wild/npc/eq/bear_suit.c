#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIK"熊大衣"NOR, ({ "bear's suit", "suit" }) );

    set_weight(6000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 4750);
        set("long", "一件很保暖的熊大衣，穿在身上使人顯得高貴許多。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 8,
            "con": 1,
            "wittiness": 5,
            "hp": 50,
        ]));
    }

    setup();
}
