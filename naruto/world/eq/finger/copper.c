#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
    set_name(YEL"�ɧ٫�"NOR, ({ "copper ring","ring" }) );
    set_weight(100);
    setup_finger_eq();

    if( !clonep() ) {
        set("unit", "�T");
        set("value", 480);
        set("long", "�@�T�ɧ٫��A���b����W���A���B���n�C\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "dodge": 4,
        ]));
    }

    setup();
}
