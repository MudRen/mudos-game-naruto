#include <npc.h>

void create()
{
    set_name("����", ({ "fox bear", "bear" }) );
    set_race("beast");
    set_level(23);

    set("long", "�H���q�W���j���A�D�`���r�ȥ͡C\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
    //  ([ "type":"obj", "id":??, "amount":1, "p1":40, "p2":100 ]),    // ����
    //  ([ "type":"obj", "id":??, "amount":1, "p1":20, "p2":100 ]),    // ����
    //  ([ "type":"obj", "id":??, "amount":1, "p1":5, "p2":100 ]),     // ����
    }) );
    setup();
}
