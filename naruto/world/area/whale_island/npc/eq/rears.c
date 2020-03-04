#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIW"�ߦզ�"NOR, ({ "rabbit's ears", "ears" }) );

    set_weight(3300);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long", "�@�ﳷ�եB�������ߦզ��A�|�����H�P�����C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 2,
        ]));
    }

    setup();
}
