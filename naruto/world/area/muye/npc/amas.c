#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("������", ({ "asma" }));
    set("title", "�᭸");
    set_race("human");
    set_level(70);
    set("camp", "muye");
    set("long", "�g�`�l�ϡA�ӥB�A���i�����������A���������ӧԪ̡A���O�L����O\n"
                "���b�d�d�褧�U�A�O�츭�����}���i�ƪ��W�Ԥ��@�C\n");


    set("age", 27);
    set("gender", "male");

    setup();
}
