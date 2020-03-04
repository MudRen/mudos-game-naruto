#include <ansi.h>
#include <armor.h>
inherit F_NECK_EQ;
void create()
{
    set_name(HIY"黃金項鍊"NOR, ({ "Gold necklace", "necklace" }) );
    set_weight(1500);
    setup_neck_eq();
    if( !clonep() ) {
        set("unit", "串");
        set("value", 20);
        set("long", "純金打造的項鍊非常的值錢\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}


