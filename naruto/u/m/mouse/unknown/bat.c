#include <npc.h>

void create()
{
    set_name("�p����", ({ "bat" }) );
    set_race("beast");
    set_level(3);

    set("long", "���q�������A�p�G�I�e�e���_�ޥi�O�|�Q�������C\n");

    set("limbs", ({ "���Y", "����", "���l", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
    //  ([ "type":"eq", "id":??, "amount":1, "p1":10, "p2":100 ]),     // ���l
    }) );

    setup();
}
