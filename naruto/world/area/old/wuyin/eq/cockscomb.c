#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIR"�����a"NOR, ({ "cockscomb" }) );

    set_weight(3000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 3000);
        set("long", "�@�������������a�A�A�Q�����H");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 8,
        ]));
    }

    setup();
}
