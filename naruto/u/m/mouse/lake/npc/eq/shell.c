#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIB"����"NOR, ({ "shell" }) );
    set_weight(1000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 500);
        set("long", "�j�F���~�ߡA�D�`����w�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 5,
        ]));
    }
    setup();
}
