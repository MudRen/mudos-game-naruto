#include <ansi.h>
inherit F_FOOD;

void create()
{
	set_name("���o����", ({ "noodles" }));
	set("unit", "�J");
	set("base_value", 900);
	set("base_weight", 300);
	set("food_stuff", 50);              // �����q�A���~�@�w�n�������q
	set("long", "�o�O�@�J�@�֩����]����Ұ������o���ѡA���Y�O�H�������D��ơA\n"
                "�t�H�����h���׸{���A�A�[�W�㳽�B�p���z�B��o�@�_���s�A�é�W\n"
                "�������a�A���ĲM���A���D�M�H�A�[�W�n�f�B�������e�N�B�����B��\n"
                "�O�B�Ȥ��B�ɤl�B���]�A�ݤF�N���H�Ԥ���y�f���C\n"
                "�T�Q����_ 900 �I��O�ȡB��O�ȡB�]�O�ȡC\n" );
	set("condition", ([
	    "food": ([
	        "name": HIG"�i����"NOR,
	        "heal_ap": 60,
	        "heal_hp": 60,
	        "heal_mp": 60,
	        "duration": 15,
	    ]),
	]) );
	setup();
}
