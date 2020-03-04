#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name("新手布衣", ({ "newbie cloth", "cloth" }) );

    set_weight(500);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 10);
        set("long", "一件尋常的新手布衣。\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
      "armor": 1,
      "wittiness": 1, 
       ]));
    }
    setup();
}

