#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(HIW"�ߧ���"NOR, ({ "rabbit tail", "tail" }) );

    set_weight(1000);
    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 1200);
        set("long", "�@�����ն�u�u���ߧ��ڡC");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 5,
            "dex": 1,
        ]));
    }

    setup();
}

