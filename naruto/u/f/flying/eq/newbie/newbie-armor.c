#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name("�s����", ({ "newbie armor", "armor" }) );

    set_weight(1000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�s���ҡA�ݤW�h�N�O�μo����Y���ꦨ���C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 2,
      ]));
    }

    setup();
}

