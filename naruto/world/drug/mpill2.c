#include <ansi.h>
inherit F_FOOD;

void create()
{
	set_name("������", ({ "middle daisy tea", "tea" }));
	set("unit", "�M");
	set("base_value", 100);             // ������ġA���ݭn�ӶQ�A�����a�R�o�_
	set("base_weight", 100);
	set("food_stuff", 20);              // �����q�A���~�@�w�n�������q
	set("long",
	    "�@�M�����A�b�i�����L�{���A�i�H��_�A���]�O��(MP)�C\n"
	    "�T�Q����_ 300 �I�]�O�ȡC\n"
	);
	set("condition", ([
	    "food": ([
	        "name": HIG"�i����"NOR,
	        "heal_mp": 20, 
	        "duration": 15,
	    ]),
	]) );
	setup();
}
