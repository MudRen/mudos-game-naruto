#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"�½��Y"NOR, ({ "pig's head", "head" }) );

    set_weight(1000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 300);
        set("long", "�@��½޳y�����Y�A�i�H���ꦨ�½ޡC");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 3,
        ]));
    }

    setup();
}
