#include <ansi.h>
#include <armor.h>
inherit F_CLOTH;
void create()
{
    set_name(HIY"黃金戰衣"NOR, ({ "Gold cloth", "cloth" }) );
    set_weight(1500);
    setup_cloth();
    if( !clonep() ) {
        set("unit", "件");
        set("value", 20);
        set("long", "純金打造的衣服非常的值錢\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
