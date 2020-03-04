#include <npc.h>

void create()
{
    set_name("�p�U", ({ "child monkey", "monkey" }) );
    set_race("beast");
    set_level(5);
    set("age", 1+random(12));
    set("long", "���۶ø����p�U�l�C\n");

    set("limbs", ({ "�U�Y", "����", "�{�l", "�U�u", "����", "�U�I", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":37, "amount":1+random(4), "p1":80, "p2":100 ]),   // �U��
        ([ "type":"obj", "id":38, "amount":1+random(2), "p1":50, "p2":100 ]),   // �U��
        ([ "type":"eq", "id":73, "amount":1, "p1":30, "p2":100 ]),              // �U��
    }) );
    setup();
    // �d�z
    set_temp("apply/attack", -10);         // �����O�q
    set_temp("apply/defend", -10);         // ���m�O�q
    set_temp("apply/exact", -10);          // �R���v
    set_temp("apply/evade", -10);          // �j�ײv
    set_temp("apply/intimidate", -10);     // ������O
    set_temp("apply/wittiness", -10);      // ���m��O
}

