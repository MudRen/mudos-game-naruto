#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(GRN"�t��"NOR, ({ "turtle armor", "armor" }) );

    set_weight(6000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 1000);
        set("long", "�@���t�ߥҡA���m��O�����A���O�ܲ­��B��_�ӴN���Q�t�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
        ]));
    }

    setup();
}
