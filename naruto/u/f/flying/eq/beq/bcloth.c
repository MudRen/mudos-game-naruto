#include <ansi.h>
#include <armor.h>

inherit F_CLOTH;

void create()
{
    set_name(BBLU+HIC"B級制式戰服"NOR, ({ "Blevel cloth", "cloth" }) );

    set_weight(1200);
    setup_cloth();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 8000);
        set("long", "B級NPC專用的制服，有不錯的防禦能力。\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
      "armor": 16,
         ]));
    }
    setup();
}

