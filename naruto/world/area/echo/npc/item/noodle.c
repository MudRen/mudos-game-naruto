#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("������", ({ "noodles", "_BEEF_NOODLES_" }));
        set("unit", "�J");
        set("base_unit", "�J");
        set("base_value", 300);
        set("base_weight", 200);
        set("food_stuff", 50);
        set("no_box", 1);
        set("long", @LONG
�ѽ��Ѫ��ѱi�Ұ����W�������ѡA�ҥΪ���ƬO�W�����סA�j���Y�M
�h�ؽ���Ҽ������������Y�A�ѱ����ߦ��l�A�f�t���ֳ\�������n�f
���סA�Y������A�@�ܴ��A���W�N��~�ҹ��������S�@������J�f��
�A���H�^���L�a�A�g�����f�C
�T�Q����_ 300 �I��O�ȡB��O�ȡB�]�O�ȡC
LONG);
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
