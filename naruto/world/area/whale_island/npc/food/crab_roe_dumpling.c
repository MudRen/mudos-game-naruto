#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name("�ɶ��N��", ({ "meat roe dumpling","dumpling" }));
                set("unit", "��");
                set("base_value", 150);
                set("base_weight", 200);
                set("food_stuff", 20);              // �����q�A���~�@�w�n�������q
                set("long", "�o�O�@���s�A�ɶ��������N��A�Q�������i�f�C\n"
                    "�T�Q����_ 150 �I��O�ȡB��O�ȡB�]�O�ȡC\n" );
set("condition", ([
    "food": ([
        "name": HIG"�i����"NOR,
        "heal_ap": 10,
        "heal_hp": 10,
        "heal_mp": 10,
        "duration": 15,
    ]),
]) );
        setup();
}
