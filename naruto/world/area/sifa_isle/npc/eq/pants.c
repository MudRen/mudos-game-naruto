#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name("���x��˪���", ({ "lounge pants", "pants" }) );

    set_weight(1200);

    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 22500);
        set("long", "���x���зǪA�ˡA�Ѩ������������x�H���Ҭ�ۡC\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 15,
        ]));
    }
    setup();
}
