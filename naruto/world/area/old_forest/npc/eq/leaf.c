#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(GRN"樹葉"NOR, ({ "a leaf", "leaf" }) );
    set_weight(800);
    setup_pants();

    if( !clonep() ) {
        set("value", 100);
        set("unit", "片");
        set("long", "一片大片的葉子，可以遮住重要部位。\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 1,
        ]));
    }
    setup();
}
