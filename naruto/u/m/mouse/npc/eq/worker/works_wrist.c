#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name(HIR"防水"HIW"手錶"NOR, ({ "Watch", "watch" }) );
    set_weight(100);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "個");
        set("value", 10);
        set("long", "防水耐撞，功能簡單且實用。\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "dex": 1,
            "str": 1,
            "int": 1,
            "armor": 4,
        ]));
    }

    setup();
}
