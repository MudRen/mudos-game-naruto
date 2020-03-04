#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(RED"大紅鼻子"NOR, ({ "red conky", "conky" }) );

    set_weight(800);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "顆");
        set("value", 12500);
        set("long", "帶在鼻子上的紅色大鼻子，馬戲團小丑搞笑時都會帶著。\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "con": 5,
        ]));
    }
    setup();
}
