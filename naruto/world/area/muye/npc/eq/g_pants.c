#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(GRN"���򨭿�"NOR, ({ "green pants", "pants" }) );

    set_weight(1500);
    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 8900);
        set("long", "�@��`��⪺�򨭿ǡA��b���W�A�|�Pı��@�Ѽ��媺�𮧡C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 10,
            "dex": 3,
        ]));
    }

    setup();
}
