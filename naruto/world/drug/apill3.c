#include <ansi.h>
inherit F_FOOD;

void create()
{
	set_name("�j�M����", ({ "big essence of chicken", "essence", "chicken" }));
	set("unit", "�M");
	set("base_value", 200);
	set("base_weight", 100);
	set("food_stuff", 30);             // �����q�A���~�@�w�n�������q
	set("long",
	    "�@�M����A�b�i�����L�{���A�i�H��_�A����O��(AP)�C\n"
	    "�T�Q����_ 600 �I��O�ȡC\n"
	);
	set("condition", ([
	    "food": ([
	        "name": HIG"�i����"NOR,
	        "heal_ap": 40, 
	        "duration": 15,
	    ]),
	]) );
	setup();
}
