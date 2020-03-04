#include <ansi.h>
#include <armor.h>
inherit F_CLOTH;

void create()
{
    set_name(HIW"白袍"NOR, ({ "white robe", "robe" }));
    set_weight(1000);
    setup_cloth();
    if( !clonep() ) {
        set("unit", "件");
        set("value", 500);
        set("long", "很普通的白色長袍。\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 5,
        ]));
    }
    setup();
}
