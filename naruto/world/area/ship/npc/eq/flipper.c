#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(GRN"��c"NOR, ({ "flipper" }) );

    set_weight(1000);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 31500);
        set("long", "���C��}�x�@�몺�c�l�A��b�����ֳt��ʡC\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 5,
            "evade": 12,
        ]));
    }
    setup();
}
