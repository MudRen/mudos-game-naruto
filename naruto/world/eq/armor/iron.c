#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIK"�K�ݥ�"NOR, ({ "iron armor", "armor" }) );

    set_weight(4000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 500);
        set("long", "�@����K���y���ݥҡA���Ѱ�¦���O�@�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 5,
        ]));
    }

    setup();
}

