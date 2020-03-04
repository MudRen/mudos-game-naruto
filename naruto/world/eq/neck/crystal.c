#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIC"����"NOR"����", ({ "crystal necklace", "necklace" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 3000);
        set("long", "�W�Y���@�����G�M�z�������A�O�������˹��~�C\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "hp": 60,
        ]));
    }

    setup();
}