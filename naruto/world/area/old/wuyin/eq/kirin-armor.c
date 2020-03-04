#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
        set_name(HIW"麒麟寶甲"NOR, ({ "kirin armor","armor" }) );
        set_weight(3000);
        setup_armor();

        if( !clonep() ) {
                set("unit", "件");
                set("value", 1000);
                set("long",
                        "一套雪白的護甲，麟片是釘刺構成的的，刺刺的不怎麼好穿上它。\n");
                set("wear_as", "armor");
                set("apply_armor/armor", ([
                        "armor" :10,
                        "con" :2
                ]));
        }

        setup();
}
