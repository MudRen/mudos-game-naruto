#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;

void create()
{
    set_name("����", ({ "false teeth", "teeth" }) );

    set_weight(800);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 2000);
        set("long", "����߱ڪ������A�ΨӴۼĥΪ��C\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
                "armor": 2,
        ]));
    }
    setup();
}


