#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(RED"�c�s�u"NOR, ({ "dragon boots", "boots" }) );

    set_weight(1500);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 8500);
        set("long", "�z�ۤ@�Ѩ��𪺹u�l�A��[�F�]�\�|�ۨӴc�B�C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
        	"armor": 3,
            "exact": 5,
            "intimidate": 5,
        ]));
    }

    setup();
}