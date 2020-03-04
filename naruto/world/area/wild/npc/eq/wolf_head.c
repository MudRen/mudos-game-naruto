#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(YEL"�T�Y"NOR, ({ "wolf's head", "head" }) );

    set_weight(1000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long", "�@��T�y�����Y�A�i�H���ꦨ�T�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 2,
        ]));
    }

    setup();
}
