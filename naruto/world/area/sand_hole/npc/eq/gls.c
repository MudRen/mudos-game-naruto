#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name(HIK"��"NOR"���O", ({ "gls" }) );

    set_weight(1500);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "�~");
        set("value", 34300);
        set("no_box", 1);
        set("long", "�{�����r���Ҥ~�O�u���������O��C\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "con": 5,
            "dex": 2,
        ]));
    }
    setup();
}
