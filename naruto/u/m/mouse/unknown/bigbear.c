#include <npc.h>

void create()
{
    set_name("�j����", ({ "big fox bear", "bear" }) );
    set_race("beast");
    set_level(25);

    set("long", "���j�������A�ݰ_�ӧ�[���r�C\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
    //  ([ "type":"obj", "id":??, "amount":1, "p1":50, "p2":100 ]),    // ����
    //  ([ "type":"obj", "id":??, "amount":1, "p1":20, "p2":100 ]),    // ����
    //  ([ "type":"obj", "id":??, "amount":1, "p1":10, "p2":100 ]),    // ���x
    }) );
    setup();
}

