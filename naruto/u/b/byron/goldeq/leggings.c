#include <ansi.h>
#include <armor.h>
inherit F_LEG_EQ;
void create()
{
    set_name(HIY"�����@�L"NOR, ({ "Gold leggings", "leggings" }) );
    set_weight(1500);
    setup_leg_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y���@�L�D�`���ȿ�\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}

