#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;
void create()
{
    set_name(HIY"黃金盔甲"NOR, ({ "Gold armor", "armor" }) );
    set_weight(1500);
    setup_armor();
    if( !clonep() ) {
        set("unit", "件");
        set("value", 20);
        set("long", "閃閃發亮的黃金打造的盔甲 沉重無比\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
