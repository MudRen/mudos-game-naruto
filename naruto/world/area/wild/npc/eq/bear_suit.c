#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIK"���j��"NOR, ({ "bear's suit", "suit" }) );

    set_weight(6000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 4750);
        set("long", "�@��ܫO�x�����j��A��b���W�ϤH��o���Q�\�h�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 8,
            "con": 1,
            "wittiness": 5,
            "hp": 50,
        ]));
    }

    setup();
}
