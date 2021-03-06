#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(YEL"狙擊王"HIR"面具"NOR, ({ "snipe mask", "mask" }) );
    set_weight(1000);
    setup_face_eq();
    if( !clonep() ) {
        set("unit", "塊");
        set("value", -1);
        set("no_box", 1);
        set("long", "狙擊王所配帶的面具，看起來像個向日葵，有點怪。\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "armor": 20,
            "exact": 30,
            "dodge": 10,
            "dex": 10,
        ]));
    }
    setup();
}
