#include <npc.h>

void create()
{
    set_name("�p��", ({ "small bear", "bear" }) );
    set_race("beast");
    set_level(23);

    set("long", "�@���ݰ_�ӫܥi�R���p��\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"obj", "id":23, "amount":1, "p1":50, "p2":100 ]),   // ����
        ([ "type":"food", "id":21, "amount":1, "p1":5, "p2":100 ]),   // ���x
    }) );

    setup();
}
