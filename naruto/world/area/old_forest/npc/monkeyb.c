#include <npc.h>

void create()
{
    set_name("���U", ({ "male monkey", "monkey" }));
    set_race("beast");
    set_level(15);
    set("age", 16+random(40));
    set("long", "�������Ӫ��j�U�l�A�ɱ`�s�s�s�Ӥ����C\n");
    set("limbs", ({ "�U�Y", "����", "�{�l", "�U�u", "����", "�U�I", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("set_drop", ({
        ([ "type":"obj", "id":37, "amount":1+random(9), "p1":50, "p2":100 ]),   // �U��
        ([ "type":"obj", "id":38, "amount":1+random(5), "p1":70, "p2":100 ]),   // �U��
        ([ "type":"eq", "id":73, "amount":1, "p1":50, "p2":100 ]),              // �U��
        ([ "type":"food", "id":43, "amount":1+random(1), "p1":50, "p2":100 ]),  // �U�x
        ([ "type":"food", "id":42, "amount":1, "p1":10, "p2":100 ]),            // �U��
        ([ "type":"obj", "id":36, "amount":1, "p1":5, "p2":100 ]),              // �j�Ѧa��
    }) );
    setup();
}