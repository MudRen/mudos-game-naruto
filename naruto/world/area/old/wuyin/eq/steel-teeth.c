#include <ansi.h>
#include <armor.h>
inherit F_FACE_EQ;

void create()
{
    set_name(HIW"���"NOR, ({ "steel teeth", "teeth" }) );

    set_weight(1200);
    setup_face_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5000);
        set("long", "����߱ڪ��S�����A�]�O�ΨӴۼĥΪ��C\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
                "armor": 2,
                "con": 3,
        ]));
    }
    setup();
}
