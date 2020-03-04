#include <npc.h>

void create()
{
    set_name("���U", ({ "female monkey", "monkey" }) );
    set_race("beast");
    set_level(10);
    set("age", 16+random(30));
    set("long", "��������U�l�A�����`�O��۴X���p�U�l�C\n");
    set("limbs", ({ "�U�Y", "����", "�{�l", "�U�u", "����", "�U�I", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":37, "amount":1+random(7), "p1":70, "p2":100 ]),   // �U��
        ([ "type":"obj", "id":38, "amount":1+random(5), "p1":60, "p2":100 ]),   // �U��
        ([ "type":"eq", "id":73, "amount":1, "p1":40, "p2":100 ]),              // �U��
        ([ "type":"food", "id":43, "amount":1, "p1":30, "p2":100 ]),            // �U�x
        ([ "type":"obj", "id":36, "amount":1, "p1":1, "p2":100 ]),              // �j�Ѧa��
    }) );
    setup();
    // �d�z
    set_temp("apply/attack", -5);         // �����O�q
    set_temp("apply/defend", -5);         // ���m�O�q
    set_temp("apply/exact", -10);          // �R���v
    set_temp("apply/evade", -10);          // �j�ײv
    set_temp("apply/intimidate", -5);     // ������O
}
