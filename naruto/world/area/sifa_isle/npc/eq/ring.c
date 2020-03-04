#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
    set_name(HIY"�q�k���P��"NOR, ({ "court martial ring", "ring" }) );
    set_weight(200);
    setup_finger_eq();
    if( !clonep() ) {
        set("unit", "�T");
        set("value", 29600);
        set("no_box", 1);
        set("long", "�H�x�q�k�q�̰����P�����٫��A�W���g�F��Ӧr�u�����v�C\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "heavy hit": 10,
            "int": 5,
            "armor": 1,
        ]));
    }
    setup();
}
