#include <ansi.h>
#include <armor.h>
inherit F_CLOTH;
void create()
{
    set_name(BRED+HIR"���~�P�@"NOR, ({ "blood cloth", "cloth" }) );
    set_weight(100);
    setup_cloth();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī���Ũ\n");
        set("wear_as", "cloth");
        set("apply_armor/cloth", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 80,
            "exact": 5,
            "evade": 20,
            "wittiness": 20,
            "dodge": 50,
        "exact": 1000,
        "evade": 1000,
        "intimidate": 1000,
        "wittiness": 1000,
        "move": 1000,
        "carriage": 1000,

        ]));
        set("wear_msg",RED"$N��W"+name()+RED"�|�P���o�ۭY���Y�L�������I\n"NOR);
    }

    setup();
}

