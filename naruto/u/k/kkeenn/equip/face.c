#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;
void create()
{
    set_name(BRED+HIR"���~���@"NOR, ({ "blood face", "face" }) );
    set_weight(100);
    setup_face_eq();
    if( !clonep() ) {
        set("unit", "�i");
        set("value", 0);
        set("long", "�㦳�����\�Ī����n\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 10,
            "continual hit": 50,
            "dodge": 50,
            "parry": 50,
            "combat": 50,
            "ninja": 50,
            "magic": 50,
            "force": 50,
            "savage hit": 50,
            "heavy hit": 50,         
        ]));
        set("wear_msg",RED"$N���W"+name()+RED"���P�ɡA���B��M�ǨӤ@�}�������z�I\n"NOR);
    }

    setup();
}

