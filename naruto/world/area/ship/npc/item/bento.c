#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name("����K��", ({ "bento" }));
        set("unit", "��");
        set("base_value", 600);
        set("base_weight", 250);
        set("food_stuff", 50);              // �����q�A���~�@�w�n�������q
        set("long", "��U����Υ~�X�ɥ��ƪ����n���~�A�ѭ��N�h�һs�@���S�s����K��\n"
                    "�A�K��̩ҥΪ����O�@�Ǫ�����q�W���S���A�����U���S��o�]����\n"
                    "�N�h���ջs�ϱo���D�o�H�X�Ӭ��@�A���F�������t�椧�~�A�̭��n��\n"
                    "�N�O�D��u�סv���D���оA���A�Y�_�ӫܦ��f�P�C�b�Y�L�o�ӫK��\n"
                    "��Pı���������O���ӤF�A�G�M�O�̴Ϊ��K��C\n"
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
