#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("���x�u�S���m", ({ "singlet" }) );

    set_weight(1200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5000);
        set("long", "���x���зǪA�ˡA���Цܤh�L���q���|��ۡC\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 10,
        ]));
    }
    setup();
}
