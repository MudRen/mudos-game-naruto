#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;
void create()
{
    set_name(BRED+HIR"���~���@"NOR, ({ "blood armor", "armor" }) );
    set_weight(100);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī�����\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 90,
            "exact": 30,
            "hp"   : 9999,
            "ap"   : 9999,
            "mp"   : 9999,
        ]));
        set("wear_msg",RED"$N��W"+name()+RED"�|�P�j���۲H�H����{���I\n"NOR);
    }

    setup();
}

