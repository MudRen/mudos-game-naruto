#include <ansi.h>
#include <armor.h>
inherit F_HEAD_EQ;

void create()
{
    set_name(GRN"���l��"NOR, ({ "coconut shell", "shell" }) );
    set_weight(1500);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long", "���l���~�֡A�D�`��w�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 2,
        ]));
    }
    setup();
}
