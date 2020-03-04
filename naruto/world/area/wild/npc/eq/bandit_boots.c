#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name("�s�D�c", ({ "bandit boots", "boots" }) );

    set_weight(3000);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 3400);
        set("long", "�@����ۥi�H���A�����L�n�L���C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 4,
            "dex" : 1,
            "int" : 1,
        ]));
    }

    setup();
}
