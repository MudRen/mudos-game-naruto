#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;
void create()
{
    set_name(HIY"��������"NOR, ({ "Gold armor", "armor" }) );
    set_weight(1500);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�{�{�o�G���������y������ �I���L��\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
