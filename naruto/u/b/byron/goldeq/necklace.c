#include <ansi.h>
#include <armor.h>
inherit F_NECK_EQ;
void create()
{
    set_name(HIY"��������"NOR, ({ "Gold necklace", "necklace" }) );
    set_weight(1500);
    setup_neck_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y������D�`���ȿ�\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}


