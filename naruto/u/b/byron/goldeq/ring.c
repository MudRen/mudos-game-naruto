#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;
void create()
{
    set_name(HIY"�����٤l"NOR, ({ "Gold ring", "ring" }) );
    set_weight(1500);
    setup_finger_eq();
    if( !clonep() ) {
        set("unit", "�u");
        set("value", 20);
        set("long", "�ª����y���٤l�D�`���ȿ�\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}

