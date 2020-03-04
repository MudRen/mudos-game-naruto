#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(YEL"�T�}"NOR, ({ "wolf's afterward feet", "feet" }) );

    set_weight(2000);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long", "�@��T����}�A���A�i�H�˦��T�C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 2,
        ]));
    }

    setup();
}
