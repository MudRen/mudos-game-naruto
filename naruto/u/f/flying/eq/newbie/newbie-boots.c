#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name("�s��c", ({ "newbie boots","boots" }) );

    set_weight(100);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�o�������s��c�A��W�h�}���Ʒƪ��C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "move": 1,
        ]));
    }

    setup();
}

