#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("���m", ({ "shirt" }) );

    set_weight(800);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 500);
        set("long", "�@��ܮe���l�������m�C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 2,
            "evade": 2,
        ]));
    }
    setup();
}
