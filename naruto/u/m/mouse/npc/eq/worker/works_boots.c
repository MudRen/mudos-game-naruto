#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(HIW"��"HIB"��"NOR"�c", ({ "Crampon", "crampon" }) );

    set_weight(1500);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "���ƪ��u�@�c�A��֤u�a�M�I�o�ͪ����v�C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 10,
            "evade": 10,
            "wittiness": 10,
        ]));
    }
    setup();
}
