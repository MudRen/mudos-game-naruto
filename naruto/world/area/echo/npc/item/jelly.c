#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("�J�խ�", ({ "albumin jelly", "jelly" }));
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 100);            // ������ġA���ݭn�ӶQ�A�����a�R�o�_
        set("base_weight", 100);
        set("food_stuff", 5);              // �����q�A���~�@�w�n�������q
        set("long", "�@���γD�J�ջs�����G��A����[����O�^�_�C\n"
                    "�T�Q����_ 300 �I��O�ȡC\n" );
set("condition", ([
    "food": ([
        "name": HIG"�i����"NOR,
        "heal_hp": 20,
        "duration": 15,
    ]),
]) );
    setup();
}

