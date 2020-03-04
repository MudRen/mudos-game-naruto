#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(YEL"���Y��"NOR, ({ "copper helmet", "helmet" }) );

    set_weight(3000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 4000);
        set("long", "�@���۷�@�Ϊ��Y���A���L�]�L���a�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 8,
        ]));
    }

    setup();
}
