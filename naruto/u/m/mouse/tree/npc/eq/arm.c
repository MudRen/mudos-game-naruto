#include <ansi.h>
#include <armor.h>
inherit F_WRIST_EQ;

void create()
{
    set_name(RED"��"HIR"���u"NOR, ({ "hard arm", "arm" }) );
    set_weight(3000);
    setup_wrist_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 4100);
        set("long", "�U�����u�A�����⪺��֦��G�󦳫¤O�C");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "armor": 2,
            "str": 3,
        ]));
    }
    setup();
}
