#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(RED"�j����l"NOR, ({ "red conky", "conky" }) );

    set_weight(800);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 12500);
        set("long", "�a�b��l�W������j��l�A�����Τp���d���ɳ��|�a�ۡC\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "con": 5,
        ]));
    }
    setup();
}
