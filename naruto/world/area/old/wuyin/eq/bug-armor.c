#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(GRN"������"NOR, ({ "bug armor", "armor" }) );

    set_weight(6000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 1000);
        set("long", "�@������ҡA��W�h���@�ثO�@��A�b��L�̤����Q�ĤH�o�{�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
                
        ]));
    }

    setup();
}

