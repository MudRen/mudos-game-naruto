#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIW"�Ф�U"NOR, ({ "plume hat", "hat" }) );

    set_weight(500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long", "�@�������Τ���򰵦��o�Ф�U�A�۷�n�ݡC");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 2,
        ]));
    }

    setup();
}
