#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name("�s��ֱa", ({ "newbie belt", "belt" }) );
    set_weight(100);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�@���}�}���ꪺ�p�ֱa�A�w�g�L�k�ݥX�O�Τ�����ƻs���C\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}


