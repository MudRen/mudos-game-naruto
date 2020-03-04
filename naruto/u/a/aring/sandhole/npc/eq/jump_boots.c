#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(BCYN"���u�O�c"NOR, ({ "jump boots", "boots" }) );

    set_weight(1200);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 2750);
        set("long", "��W���A�K�i��|��gonna�����Pı�C\n");
        set("wear_as", "feet_eq");
        set("wear_msg", HIY"$N��W$n"HIY"�F��A�K���n�۵ۡG �w�ߤf�R���p���L���\n"NOR);
        set("apply_armor/feet_eq", ([
            "str": -5,
            "evade": 5,
            "dex": 2,
            "armor": 4,
        ]));
    }

    setup();
}

