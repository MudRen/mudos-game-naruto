#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(NOR+BRED"�ܥ��U���n"NOR, ({ "jopie mask", "mask" }) );

    set_weight(1000);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 40500);
        set("long", "��kF4�٥������n�C\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "intimidate": 11,
            "armor": 1,
            "continual hit": 10,
            "con": 2,
        ]));
    }
    setup();
}

