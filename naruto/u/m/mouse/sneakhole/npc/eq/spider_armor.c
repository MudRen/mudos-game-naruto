#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(RED"�j����"NOR, ({ "queen spider armor", "armor" }) );
    set_weight(5000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 12950);
        set("long", "�ӦZ�j�諸����~�ߡA�ݰ_�Ӧ��I���ߡC\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 15,
            "str": 1,
            "wittiness": 5,
            "hp": 50,
            "mp": 30,
        ]));
    }
    setup();
}
