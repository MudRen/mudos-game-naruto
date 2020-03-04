#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(GRN"草帽"NOR, ({ "straw hat", "hat" }) );

    set_weight(500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 100);
        set("long", "一頂用草繩編織而成的草帽，看起來相當的別緻。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}
