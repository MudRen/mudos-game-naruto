#include <armor.h>
#include <ansi.h>

inherit F_CLOTH;

void create()
{
    set_name(HIK"�½ޥ�"NOR, ({ "pig's fur", "fur" }));
    set_weight(1000);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "�i");
        set("value", 200);
        set("long", "�@�i�K�²��W���½ޥ֡C\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 2,
        ]));
    }

    setup();
}