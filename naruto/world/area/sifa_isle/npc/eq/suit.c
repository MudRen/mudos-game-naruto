#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("���x��ˤW��", ({ "lounge suit", "suit" }) );

    set_weight(1200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 7500);
        set("long", "���x���зǪA�ˡA�Ѩ������������x�H���Ҭ�ۡC\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 15,
        ]));
    }
    setup();
}
