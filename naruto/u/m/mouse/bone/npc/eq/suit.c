#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIG"�q�j��"NOR, ({ "ton suit", "suit" }) );
    set_weight(6000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 5200);
        set("long", "�q���Q�Ҭ諸��A�A�ݰ_�ӫp���O�x�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
            "dex": 1,
            "hp": 70,
        ]));
    }
    setup();
}
