#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name("�ե��c", ({ "white cloth shoes", "shoes" }) );

    set_weight(1200);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 1600);
        set("long", "�ǻ������ubad boy�v�ڻ���F�o�c�l�A�q��|�ܦn�C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 2,
            "int" : 2,
        ]));
    }

    setup();
}
