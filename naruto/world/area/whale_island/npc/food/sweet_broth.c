#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("����", ({ "sweet broth", "broth" }));
        set("unit", "��");
        set("base_unit", "��");
        set("base_value", 600);
        set("base_weight", 200);
        set("food_stuff", 40);
        set("long","�b�Y���N���ܤ@�J����h���o���٦��Ш��������a�C\n"
                    "�T�Q����_ 600 �I��O�ȡB��O�ȡB�]�O�ȡC\n" );
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
