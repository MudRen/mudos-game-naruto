#include <ansi.h>
#include <armor.h>
inherit F_PANTS;
void create()
{
    set_name(HIY"黃金長褲"NOR, ({ "Gold pants", "pants" }) );
    set_weight(1500);
    setup_pants();
    if( !clonep() ) {
        set("unit", "件");
        set("value", 20);
        set("long", "純金打造的褲子非常的值錢\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}


