#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
    set_name("�s��٫�", ({ "newbie ring","ring" }) );
    set_weight(100);
    setup_finger_eq();

    if( !clonep() ) {
        set("unit", "�T");
        set("value", 10);
        set("long", "�@�T�s��٫��A���Y�s�����S�����@��O�C\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "intimidate": 1,
        ]));
    }

    setup();
}


