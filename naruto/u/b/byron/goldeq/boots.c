#include <ansi.h>
#include <armor.h>
inherit F_FEET_EQ;
void create()
{
    set_name(HIY"�����Թu"NOR, ({ "Gold boots", "boots" }) );
    set_weight(1500);
    setup_feet_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�ª����y���u�l�D�`���ȿ�\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
