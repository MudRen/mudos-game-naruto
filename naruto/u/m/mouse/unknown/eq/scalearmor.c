#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIK"���"NOR, ({ "scale armor", "armor" }) );
    set_weight(8000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 4750);
        set("long", "�h�A���뤧��һs�A�~����W��T�A���m�Q���C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 12,
        ]));
    }
    setup();
}
