#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("�w´��", ({ "knit cloth", "cloth" }) );

    set_weight(1200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 500);
        set("long", "�@��¤�u�s´����A�A�ܭ@��C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 5,
        ]));
    }
    setup();
}

