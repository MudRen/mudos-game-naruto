#include <ansi.h>
#include <armor.h>

inherit F_ARMOR;

void create()
{
    set_name(NOR+MAG"�ȴߥ�"NOR, ({ "scorpion armor", "armor" }) );
    set_weight(730);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 500);
        set("long", "�Ȥl�~�ߧΦ�����w�@�ҡA�����q�Q���������ܦh�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor_eq", ([
            "dex": 1,
            "con": -1,
            "dodge": 2,
            "armor": 4,
        ]));
    }

    setup();
}

