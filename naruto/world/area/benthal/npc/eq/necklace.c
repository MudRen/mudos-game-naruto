#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIC"海洋"HIW"之心"NOR, ({ "sea heart necklace", "necklace", "heart" }) );
    set_weight(1000);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "條");
        set("value", 46400);
        set("no_box", 1);
        set("long", "水藍色的心形項鍊，當陽光照耀時水藍色顯得十分生動。\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "ap": 150,
            "armor": 5,
            "int": 2,
        ]));
    }
    setup();
}
