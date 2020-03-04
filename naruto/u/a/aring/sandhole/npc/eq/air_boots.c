#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(HIR"�Ů�c"NOR, ({ "air boots", "boots" }) );

    set_weight(1000);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 25250);
        set("long", "�����c�O�Ȥ���Air Jordan corssover�һs���A���y���q�@���C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "dex": 5,
            "evade": 5,
            "dodge": 5,
            "armor": 6,
        ]));
    }

    setup();
}

