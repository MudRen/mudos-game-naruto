#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(YEL"�w���U"NOR, ({ "Safe helmet", "helmet" }) );

    set_weight(1500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�u�H�ұa���U�l�A�W���g�ۡy�w���Ĥ@�z");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 10,
            "exact": 30,
        ]));
    }

    setup();
}
