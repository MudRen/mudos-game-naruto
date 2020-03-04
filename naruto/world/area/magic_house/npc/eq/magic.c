#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name(MAG"�]"NOR"�N"HIM"��"NOR"��", ({ "magic finesse", "finesse" }) );
    set_weight(500);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 14500);
        set("long", "�a�W���H�K�|�Pı�ⳡ�Ҩ������q�ܻ��F�A�]�k�몺����C\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "evade": 5,
            "wittiness": 3,
            "con": 2,
            "armor": 5,
        ]));
    }
    setup();
}
