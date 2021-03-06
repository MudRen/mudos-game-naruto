#include <ansi.h>
#include <armor.h>
inherit F_CLOTH;

void create()
{
    set_name(HIC"員工"HIW"制服"NOR, ({ "cloth" }));

    set_weight(1000);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 200);
        set("long", "平時打掃員工所穿著的制服。\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 200,                             //防禦(armor)
            "str": 20,
            "int": 20,
        ]));
    }

    setup();
}
