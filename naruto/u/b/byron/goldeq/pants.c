#include <ansi.h>
#include <armor.h>
inherit F_PANTS;
void create()
{
    set_name(HIY"��������"NOR, ({ "Gold pants", "pants" }) );
    set_weight(1500);
    setup_pants();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y���Ǥl�D�`���ȿ�\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}


