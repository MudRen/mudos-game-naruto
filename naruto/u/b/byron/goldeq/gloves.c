#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;
void create()
{
    set_name(HIY"������M"NOR, ({ "Gold gloves", "gloves" }) );
    set_weight(1500);
    setup_hand_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y����M�D�`���ȿ�\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
