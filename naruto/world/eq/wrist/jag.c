#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name("�y���@��", ({ "jag wrist", "wrist" }) );
    set_weight(100);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long", "�@�ӤW�Y���@��y�몺�@�áA�p�߳Q���C\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "armor": 2,
        ]));
    }

    setup();
}
