#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name("�G��U", ({ "jelly hat", "hat" }) );
    set_weight(400);
    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 400);
        set("long", "�a�b�Y�W�n�n�ߢߪ��A�u�O���I��C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 4,
        ]));
    }
    setup();
}
