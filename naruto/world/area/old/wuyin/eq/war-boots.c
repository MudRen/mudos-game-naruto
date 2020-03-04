#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(HIY"�ԮȤ��u"NOR, ({ "war boots", "boots" }) );

    set_weight(50000);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 7000);
        set("long", "���h�̦b�Գ��W��۪��c�l�A�Q���p���C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "move": 10,
            "armor": 5,
            "dex": -1,
        ]));
    }

    setup();
}
