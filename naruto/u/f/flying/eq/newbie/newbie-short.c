#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name("�s��u��", ({ "newbie short", "short" }) );
    set_weight(200);
    setup_pants();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�s��u�ǡA�ݤW�h�S�񧿥]�n�W�h�֡C\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 1,
        ]));
    }

    setup();
}

