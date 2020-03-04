#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name(GRN"�D�ָy�a"NOR, ({ "snake belt", "belt" }) );
    set_weight(2000);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 3900);
        set("long", "�@���H�D�ֻs�����y�a�A�W�Y���O�o���᯾�A���ʤQ���۷�@�ΡC\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 2,
            "con": 1,
            "savage hit": 5,
        ]));
    }

    setup();
}
