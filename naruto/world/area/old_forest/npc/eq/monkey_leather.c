#include <ansi.h>
#include <armor.h>
inherit F_CLOTH;

void create()
{
    set_name(YEL"�U��"NOR, ({ "monkey leather", "leather" }));
    set_weight(600);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "�i");
        set("value", 100);
        set("long", "�q�U�l���W��U�Ӫ��U�֡C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 1,
        ]));
    }
    setup();
}
