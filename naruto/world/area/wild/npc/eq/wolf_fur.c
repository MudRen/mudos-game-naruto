#include <armor.h>
#include <ansi.h>

inherit F_CLOTH;

void create()
{
    set_name(YEL"�T��"NOR, ({ "wolf's fur", "fur" }));
    set_weight(1000);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "�i");
        set("value", 300);
        set("long", "�@�i���R���T�֡C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 3,
        ]));
    }

    setup();
}