#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(RED"���w��"NOR, ({ "amulet" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 450);
        set("long", "���䪺�p�q�H�K�D�Ӫ����w�šA�@�ӯ}�}�����U�l�A�̭��˵ۤ@�i��\n"
                    "���⪺�ȡA�W���g�ۡu�O���X�J���w�v���L�r��n�C��K�A�����Ȥ]\n"
                    "�]���O�H�K���@�i�Ϣ��ȥΤ⼹�@����W�W�Y�Y�A���ޫ��ݳ�ı�o\n"
                    "�o�ӥ��w�Ť@�w�O�¤߳f�C\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "evade": 3,
        ]));
    }
    setup();
}
