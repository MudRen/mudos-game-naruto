#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(HIW"�L�_����"NOR, ({ "under pants", "pants" }) );

    set_weight(1500);
    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5000);
        set("long", "�@�󵷽誺���ǡA�A�`�N��W���èS�������_���A��_�����ӷ|�ܳz��ۦb�C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 8,
            "int": 1,
        ]));
    }

    setup();
}

