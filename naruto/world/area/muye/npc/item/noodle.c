#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name("�ɶ���Į�j���t�Y���G����", ({ "noodles", "_GOOD_FOOD_" }));
                set("unit", "��");
                set("base_unit", "�J");
                set("base_value", 600);
                set("base_weight", 250);
                set("food_stuff", 60);              // �����q�A���~�@�w�n�������q
    set("no_box", 1);
                set("long", "�o�O�@�J�@�֩����]����S�s�����ѡC\n"
                    "�T�Q����_ 300 �I��O�ȡB��O�ȡB�]�O�ȡC\n");
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
