#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name("�s��U", ({ "newbie hat", "hat" }) );

    set_weight(300);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�@���p�p���s��U�A�W�����}�}�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 1,
            "exact": 1,
        ]));
    }

    setup();
}

