#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;

void create()
{
    set_name(HIK"����"NOR, ({ "black glasses", "glasses" }) );
    set_weight(500);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 450);
        set("long", "�@������۷�ª�����A���ۥ������D�٬ݤ��ݱo����C\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "exact": 3,
        ]));
    }
    setup();
}
