#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name("�s�ͥ���", ({ "Newchar Armor", "armor" }) );

    set_weight(1500);
    setup_armor();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 20);
        set("long", "�@���M�����_�b�@�_���p���ҡA�Ѩ��j�v�s�@�C\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 3,
        ]));
    }
    setup();
}
