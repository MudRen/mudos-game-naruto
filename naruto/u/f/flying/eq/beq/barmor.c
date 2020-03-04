#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(BBLU+HIC"B級制式盔甲"NOR, ({ "Blevel armor", "armor" }) );

    set_weight(3000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 31500);
        set("long", "B級NPC的標準制服，有不錯的防禦能力。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 21,
      ]));
    }

    setup();
}

