#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name("幫寶寶尿包", ({ "niao bao",}) );
    set_weight(800);
    setup_pants();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 100);
        set("long", "一件嬰兒用的尿包，還帶了點屎味。\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "hp": 9999,
            "mp": 9999,
            "ap": 9999,
            ]));
    }
  setup();
}

