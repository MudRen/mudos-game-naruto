#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(YEL"狼尾"NOR, ({ "wolf's tail", "tail" }) );
    set_weight(800);
    setup_pants();

    if( !clonep() ) {
        set("unit", "條");
        set("value", 100);
        set("long", "一條狼的尾巴，讓你可以裝扮成狼。\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 1,
        ]));
    }

    setup();
}