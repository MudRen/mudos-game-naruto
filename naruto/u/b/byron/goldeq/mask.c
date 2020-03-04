#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;
void create()
{
    set_name(HIY"黃金面罩"NOR, ({ "Gold mask", "mask" }) );
    set_weight(1500);
    setup_face_eq();
    if( !clonep() ) {
        set("unit", "面");
        set("value", 20);
        set("long", "純金打造的面具非常的值錢\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
