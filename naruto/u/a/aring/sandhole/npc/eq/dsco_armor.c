#include <ansi.h>
#include <armor.h>

inherit F_ARMOR;

void create()
{
    set_name(NOR+RED"���ȥ�"NOR, ({ "double-scorpion armor", "armor" }) );
    set_weight(870);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 6300);
        set("long", "�Ȥl�~�ߧΦ�����w�@�ҡC\n");
        set("wear_as", "armor");
        set("apply_armor/armor_eq", ([
            "dex": 1,
            "con": -1,
            "str": 1,
            "int": 1,
            "combat": -15,
            "wittiness": 7,                    
    ]));
    }

    setup();
}

