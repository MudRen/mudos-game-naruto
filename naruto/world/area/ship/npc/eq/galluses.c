#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(HIB"�Q�a��"NOR, ({ "galluses" }) );

    set_weight(800);
    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 8900);
        set("long", "�K�󬡰ʪ����ǡA�H��̷R�諸�Ǥl�C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 5,
            "dex": 2,
            "exact": 5,
            "evade": 5,
        ]));
    }
    setup();
}
