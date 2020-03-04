#include <ansi.h>
#include <armor.h>

inherit F_FACE_EQ;

void create()
{
    set_name(HIK"�¦Ⲵ�n"NOR, ({ "eyepatch" }) );

    set_weight(1500);

    setup_face_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 8000);
        set("long", "�@���沴���n�A�ΨӭA�ӥΪ��C\n");
        set("wear_as", "face_eq");
        set("apply_armor/face_eq", ([
            "wittiness": 1,
            "armor": 1,
        ]));
    }

    setup();
}
