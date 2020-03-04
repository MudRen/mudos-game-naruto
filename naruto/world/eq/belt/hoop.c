#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name(BWHT+HIB"�I�԰�"NOR, ({ "hula hoop", "hoop" }) );
    set_weight(1000);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 750);
        set("long", "�@�����A�G���Ϊ��I�԰�A���_���O���ηn�]���|���b�a�W�C\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "evade": 5,
        ]));
    }

    setup();
}
