#include <ansi.h>
#include <armor.h>
inherit F_CLOTH;

void create()
{
    set_name(HIW"�ճT"NOR, ({ "white robe", "robe" }));
    set_weight(1000);
    setup_cloth();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 500);
        set("long", "�ܴ��q���զ���T�C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 5,
        ]));
    }
    setup();
}
