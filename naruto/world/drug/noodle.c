#include <ansi.h>
inherit F_FOOD;

void create()
{
	set_name("�b������", ({ "noodles" }));
	set("unit", "�J");
	set("base_value", 300);
	set("base_weight", 200);
	set("food_stuff", 50);              // �����q�A���~�@�w�n�������q
	set("long", "�o�O�۴���H�̱`�Y���i�@�֡j�b�����ѡA�տB���b���ġA�Ŀ@�ӥB\n"
                "���I�H�H���A�o�N�O�νް��H�j�����ɶ����N�X���ťզ�@���A�[�W\n"
                "���B�[�B�ªo�ը������Y�A�\�h���t�ƥH�Ϋr�l�Q�������ѡA�@�p��\n"
                "�f���O�H�g�����f�A�K�y������B�״I���t�ơB�������Ϊ����Y�A��\n"
                "��O�@�J���A�Y�F�ٷQ�A�Y���n�ѡI\n"
                "�T�Q����_ 300 �I��O�ȡB��O�ȡB�]�O�ȡC\n" );
    set("condition", ([
	    "food": ([
	        "name": HIG"�i����"NOR,
	        "heal_ap": 20,
	        "heal_hp": 20,
	        "heal_mp": 20,
	        "duration": 15,
	    ]),
	]) );
	setup();
}
