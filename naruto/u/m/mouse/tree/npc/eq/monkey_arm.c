#include <ansi.h>
#include <armor.h>
inherit F_WRIST_EQ;

void create()
{
    set_name(YEL"�U�u"NOR, ({ "monkey arm", "arm" }) );
    set_weight(800);
    setup_wrist_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 2000);
        set("long", "���U�����u�A�N�̭����Y�M����i���@�u�ϥΡC");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "armor": 4,
        ]));
    }
    setup();
}
