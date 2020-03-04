#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"������"NOR, ({ "windbreak hat", "hat" }) );

    set_weight(1000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 300);
        set("long", "�@���W�Y���������誺�U�l�A�@�ƫܷs�骺�ҼˡC");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 3,
        ]));
    }

    setup();
}
