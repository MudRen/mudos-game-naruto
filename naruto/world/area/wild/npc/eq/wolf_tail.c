#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(YEL"�T��"NOR, ({ "wolf's tail", "tail" }) );
    set_weight(800);
    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "�@���T�����ڡA���A�i�H�˧ꦨ�T�C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 1,
        ]));
    }

    setup();
}