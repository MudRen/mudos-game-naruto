#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name("�q�j�Q��", ({ "spaghetti" }));
        set("unit", "�L");
        set("base_value", 600);
        set("base_weight", 250);
        set("food_stuff", 50);              // �����q�A���~�@�w�n�������q
        set("long", "�˳ǩһs�@���q�j�Q�ѡA�ھڥ˳ǥ��H�����k�A�o���ѱ��O�L�N�ѯ�\n"
                    "�Y�i�L��g�L���͡A�M��ΥL�S���������N�ѱ����X�A�A�[�W�L\n"
                    "�S�s���q�j�Q����᧹���I�ѱ����ߦ��r�l�A�٦��ػ����X�����D�C\n"
                    "��ƭ����W�S�A�f�t�b�@�_�u�O�n�Y�����o�F�I���L�o���O�˳Ǧۤv\n"
                    "����....��ثe�����٨S�H���Y�L�����q�j�Q�ѡC\n"
                    "�T�Q����_ 600 �I��O�ȡB��O�ȡB�]�O�ȡC\n" );
    set("condition", ([
            "food": ([
                "name": HIG"�i����"NOR,
                "heal_ap": 40,
                "heal_hp": 40,
                "heal_mp": 40,
                "duration": 15,
            ]),
        ]) );
        setup();
}
