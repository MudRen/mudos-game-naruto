#include <npc.h>

void create()
{
    set_name("�j�Q�t", ({ "big turtle", "turtle" }) );
    set_race("beast");
    set_level(10);
    set("long", "�@���t�Y�t�����Q�t�C\n");
    set("limbs", ({ "�t�Y", "����", "����", "�t�}", "����" }) );
    set("verbs", ({ "bite" }) );
    set("set_drop", ({
        ([ "type":"food", "id":22, "amount":1, "p1":60, "p2":100 ]),  // �t�Y
        ([ "type":"eq", "id":3, "amount":1, "p1":20, "p2":100 ]),     // �t��
    }) );
    setup();
    add_temp("apply/defend", 40);         // ���m�O�q
}
