#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(BBLU+HIC"B�Ũ����"NOR, ({ "Blevel armor", "armor" }) );

    set_weight(3000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 31500);
        set("long", "B��NPC���зǨ�A�A�����������m��O�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 21,
      ]));
    }

    setup();
}

