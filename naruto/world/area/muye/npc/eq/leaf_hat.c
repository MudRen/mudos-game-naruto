#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(GRN"斗笠"NOR, ({ "leaf hat", "hat" }) );

    set_weight(1500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "頂");
        set("value", 22000);
        set("long", "一頂用草繩編織而成的斗笠，看起來相當的別緻。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 10,
            "exact": 10,
        ]));
    }

    setup();
}
