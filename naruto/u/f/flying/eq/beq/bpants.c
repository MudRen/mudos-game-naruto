#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(BBLU+HIC"B�Ũ����"NOR, ({ "blevel short", "short" }) );
    set_weight(1000);
    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5000);
        set("long", "B��NPC�M�Ϊ�����ǡA�����������m��O�C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 10,
        ]));
    }

    setup();
}

