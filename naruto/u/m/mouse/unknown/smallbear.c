#include <npc.h>

void create()
{
    set_name("�p����", ({ "small fox bear", "bear" }) );
    set_race("beast");
    set_level(20);

    set("long", "�p���������A�ݰ_�ӫܥi�R�C\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
    //  ([ "type":"obj", "id":??, "amount":1, "p1":40, "p2":100 ]),    // ����
    //  ([ "type":"obj", "id":??, "amount":1, "p1":10, "p2":100 ]),    // ����
    }) );
    setup();
}

