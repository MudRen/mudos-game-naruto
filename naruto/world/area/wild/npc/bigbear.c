#include <npc.h>

void create()
{
    set_name("�j��", ({ "big bear", "bear" }) );
    set_race("beast");
    set_level(27);

    set("long", "�@���ݰ_�ӫܱj���B���j����\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"obj", "id":23, "amount":1, "p1":50, "p2":100 ]),   // ����
        ([ "type":"food", "id":21, "amount":1, "p1":5, "p2":100 ]),   // ���x
        ([ "type":"eq", "id":65, "amount":1, "p1":5, "p2":100 ]),   // ���j��
    }) );

    setup();
}
