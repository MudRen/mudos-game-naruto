#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name(BBLU+HIC"B�Ũ����"NOR, ({ "blevel wrist", "wrist" }) );
    set_weight(300);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 2000);
        set("long", "B��NPC��������A�����������m��O�C\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "armor": 4,
            ]));
    }

    setup();
}

