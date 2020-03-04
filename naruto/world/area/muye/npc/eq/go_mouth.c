#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(HIY"���L"NOR, ({ "goose's mouth", "mouth" }) );

    set_weight(800);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "�i");
        set("value", 9050);
        set("long", "��o�����b�L�W�A�K�֦��@�i���������L�C\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "str": 1,
            "armor": 1,
            "attack": 5,
            "intimidate": 5,
        ]));
    }
    setup();
}
