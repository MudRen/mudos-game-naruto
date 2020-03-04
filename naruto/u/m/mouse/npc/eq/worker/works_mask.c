#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(HIW""BLK"N95�f�n"NOR, ({ "N95 Mask", "mask" }) );

    set_weight(800);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "���dSRAS�̨ΧQ���I�I�u�H�����Ƹ˳ơC\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "armor": 2,
            "exact": 10,
            "intimidate": 10,
            "continual hit": 10,
            "str": 3,
        ]));
    }
    setup();
}
