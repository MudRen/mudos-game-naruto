#include <npc.h>

void create()
{
    set_name("���Z", ({ "swan" }) );
    set_race("beast");
    set_level(15);

    set("long", "�@�����A�u���������ժ����Z�C\n");

    set("limbs", ({ "�Z�Y", "����", "����", "�Z�L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("set_drop", ({
        ([ "type":"eq", "id":63, "amount":1, "p1":5, "p2":100 ]),    // ���L
        ([ "type":"obj", "id":27, "amount":1, "p1":70, "p2":100 ]),   // �Ф�
    }) );

    setup();
}
