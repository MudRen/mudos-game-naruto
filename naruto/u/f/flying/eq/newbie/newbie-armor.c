#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name("新手木甲", ({ "newbie armor", "armor" }) );

    set_weight(1000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 10);
        set("long", "新手木甲，看上去就是用廢棄木頭拼湊成的。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 2,
      ]));
    }

    setup();
}

