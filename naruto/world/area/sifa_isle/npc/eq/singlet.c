#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("海軍短袖汗衫", ({ "singlet" }) );

    set_weight(1200);

    setup_cloth();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 5000);
        set("long", "海軍的標準服裝，雜役至士兵階段都會穿著。\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 10,
        ]));
    }
    setup();
}
