#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;

void create()
{
    set_name(HIW"剛牙"NOR, ({ "steel teeth", "teeth" }) );

    set_weight(1200);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "副");
        set("value", 5000);
        set("long", "哈比兔族的特殊剛牙，也是用來欺敵用的。\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
                "armor": 2,
                "con": 3,
        ]));
    }
    setup();
}
