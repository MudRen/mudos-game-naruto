#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name(HIW"�w��÷��"NOR, ({ "Safe rope", "rope" }) );
    set_weight(2000);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�u�a�����ƹD��A�H���Y���N�~���o�͡C\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 10,
            "con": 20,
            "savage hit": 20,
        ]));
    }

    setup();
}
