#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("���߻I", ({ "brains fat", "fat" }));
        set("unit", "��");
        set("base_value", 100);
        set("base_weight", 100);
        set("food_stuff", 5);              // �����q�A���~�@�w�n�������q
        set("long", "�@���ι����߻s�����I�A����[�ֺ믫�^�_�C\n"
                    "�T�Q����_ 300 �I��O�ȡC\n" );
set("condition", ([
    "food": ([
        "name": HIG"�i����"NOR,
        "heal_ap": 20,
        "duration": 15,
    ]),
]) );
    setup();
}
