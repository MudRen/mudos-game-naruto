#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name("�s�����", ({ "newbie wrist", "wrist" }) );
    set_weight(10);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�N���ƤW�����X�p�U�ӡA�b��W�K���@��C\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "armor": 1,
            ]));
    }

    setup();
}


