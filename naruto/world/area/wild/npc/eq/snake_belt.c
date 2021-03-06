#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name(GRN"蛇皮腰帶"NOR, ({ "snake belt", "belt" }) );
    set_weight(2000);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "條");
        set("value", 3900);
        set("long", "一條以蛇皮製成的腰帶，上頭有別緻的花紋，韌性十足相當耐用。\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 2,
            "con": 1,
            "savage hit": 5,
        ]));
    }

    setup();
}
