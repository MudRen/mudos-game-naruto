#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(HIG"��"NOR, ({ "a leaf", "leaf" }) );
    set_weight(800);
    setup_pants();

    if( !clonep() ) {
        set("value", 100);
        set("unit", "��");
        set("long", "�@���j�������l�A�i�H�B���n����C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 1,
        ]));
    }
    setup();
}
