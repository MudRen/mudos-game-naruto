#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�Ļ���", ({ "noodles" }));
    set("unit", "�J");
    set("base_value", 2000);
    set("base_weight", 100);
    set("food_stuff", 80);              // �����q�A���~�@�w�n�������q
    set("long", "�ѱi���F�����Ѫ��t�@�⵴���A�L�H�����ת��u�Ļ��ѡv�Ĥ��a��\n"
                "�A�f�P�`�����l�A�����N�ѱ��l�J�f���A�@�}�ĥ̤S���¦ު��f�P��\n"
                "���R���f���A�C�Z�ѱ����ѱ��ҧl�����@���Ѵ��}�l�o�¡A�@�}�}��\n"
                "�P���H���ĸ����A�믫��ӳ��n�_�ӤF�A�߱��]�����@���C�b�Y����\n"
                "��N���@�_�U�{�A������h����~�Ѥ����o���A�H�H�������]��N�f\n"
                "�����Ļ��h���A��b�O�J���i�h�o���n�ѡC\n"
                "�T�Q����_ 1500 �I��O�ȡB��O�ȡB�]�O�ȡC\n" );
    set("condition", ([
        "food": ([
            "name": HIG"�i����"NOR,
            "heal_ap": 100,
            "heal_hp": 100,
            "heal_mp": 100,
            "duration": 15,
        ]),
    ]) );
    setup();
}
