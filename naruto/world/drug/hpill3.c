#include <ansi.h>
inherit F_FOOD;

void create()
{
	set_name("�j�C�Y", ({ "big manto", "manto" }));
	set("unit", "��");
	set("base_value", 200);            // ������ġA���ݭn�ӶQ�A�����a�R�o�_
	set("base_weight", 100);
	set("food_stuff", 30);             // �����q�A���~�@�w�n�������q
	set("long",
	    "�@���C�Y�A�b�i�����L�{���A�i�H��_�A����O��(HP)�C\n"
	    "�T�Q����_ 600 �I��O�ȡC\n"
	);
	set("condition", ([
	    "food": ([
	        "name": HIG"�i����"NOR,
	        "heal_hp": 40, 
	        "duration": 15,
	    ]),
	]) );
	setup();
}
