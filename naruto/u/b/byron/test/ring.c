#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;
void create()
{
    set_name(MAG"���ɧ�"NOR,({"purple-jade ring","ring"}) );;
    set_weight(200);
    setup_finger_eq();
    if( !clonep() ) {
        set("unit", "�T");
        set("value", 50000);
        set("long", "�@�T���⪺�j�١A�W����۬ݤ�������r�A�x�۷ż����A�C\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "str": 5,
            "con": 5,
            "int": 5,
            "dex": 5,
            "armor": 50,
        ]));
    }
    setup();
}
