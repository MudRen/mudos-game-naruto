#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;

void create()
{
    set_name("�s�Ⲵ��", ({ "newbie glasses", "glasses" }) );

    set_weight(80);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�H��i�o���ˤl�K�W�z���������ܦ�������C\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
                "exact": 1,
             ]));
    }
    setup();
}


