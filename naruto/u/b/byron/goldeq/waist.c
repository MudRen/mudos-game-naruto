#include <ansi.h>
#include <armor.h>
inherit F_WAIST_EQ;
void create()
{
    set_name(HIY"�����y�a"NOR, ({ "Gold waist", "waist" }) );
    set_weight(1500);
    setup_waist_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y���y�a�D�`���ȿ�\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
