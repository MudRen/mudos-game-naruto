#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(GRN"鱗之鎧"NOR, ({ "scale armor", "armor" }) );
    set_weight(10000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "片");
        set("value", 0);
        set("no_box", 1);
        set("long", "密室念魚之鎧，依具現者能力強弱決定鎧甲的程度。\n");
        set("wear_as", "armor");
    }
    setup();
}