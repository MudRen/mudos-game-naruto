#include <ansi.h>
inherit F_FOOD;

void create()
{
	set_name("�C�Y", ({ "manto" }));
	set("unit", "��");
	set("base_value", 50);
	set("base_weight", 100);
	set("food_stuff", 10);              // �����q�A���~�@�w�n�������q
	set("long",
	    "�@���C�Y�A�b�i�����L�{���A�i�H��_�A����O��(HP)�C\n"
	    "�T�Q����_ 150 �I��O�ȡC\n"
	);
	set("condition", ([
	    "food": ([
	        "name": HIG"�i����"NOR,
	        "heal_hp": 10, 
	        "duration": 15,
	    ]),
	]) );
	setup();
}
