#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(GRN"��c"NOR, ({ "straw boots","boots" }) );

    set_weight(800);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "�γ¯�s�����c�l�A�ܶ��K�C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}
