#include <npc.h>

void create()
{
    set_name("��", ({ "bear" }) );
    set_race("beast");
    set_level(25);

    set("long", "�@���ݰ_�ӫܱj������\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"obj", "id":23, "amount":1, "p1":50, "p2":100 ]),   // ����
        ([ "type":"food", "id":21, "amount":1, "p1":5, "p2":100 ]),   // ���x
    }) );

    setup();
}
