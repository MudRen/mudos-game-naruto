#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIR"�ɴ�"NOR, ({ "crab shell", "shell" }) );
    set_weight(1000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 400);
        set("long", "���ɪ��~�ߡA�Z��w���C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 4,
        ]));
    }
    setup();
}
