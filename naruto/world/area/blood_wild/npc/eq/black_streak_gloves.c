#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name("�°{�q���", ({ "black streak gloves","gloves" }) );

    set_weight(1500);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 24000);
        set("long", "�o�O�@���H�����W���¦���ݩҥ��y����ҡA��a�D�`����w�C\n");
        set("wear_as", "hand_eq");
    }
    set("apply_armor/hand_eq", ([
        "armor": 8,
    ]));
    setup();
}
