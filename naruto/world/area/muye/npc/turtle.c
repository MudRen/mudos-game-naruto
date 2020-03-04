#include <npc.h>

void create()
{
    set_name("�Q�t", ({ "turtle" }) );
    set_race("beast");
    set_level(5);
    set("long", "�@���t�Y�t�����Q�t�C\n");
    set("limbs", ({ "�t�Y", "����", "����", "�t�}", "����" }) );
    set("verbs", ({ "bite" }) );
    set("set_drop", ({
        ([ "type":"food", "id":22, "amount":1, "p1":30, "p2":100 ]),   // �t�Y
        ([ "type":"eq", "id":3, "amount":1, "p1":5, "p2":100 ]),   // �t��
    }) );
    setup();
    add_temp("apply/defend", 20);         // ���m�O�q
}
