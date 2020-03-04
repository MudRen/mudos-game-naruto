#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(YEL"��U"NOR, ({ "boater" }) );
    set_weight(1);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("no_box", 1);
        set("long", "�u�|�ӡv���@���j����ǧJ�ұa����U�A�����e���F�|�ҡC�{�b��\n"
                    "�U�W���_�F�i���b�F�z������Ԥڴ��Z�ɡu�����v�㴵�Ұe���ȡA\n"
                    "�]���o����U�w�g�O�|�Ұ��F���~�̭��n���F��F�C\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "attack": 30,
            "combat": 10,
            "armor": 10,
            "intimidate": 5,
            "str": 5,
        ]));
    }
    setup();
}
