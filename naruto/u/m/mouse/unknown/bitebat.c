#include <npc.h>

void create()
{
    set_name("�l�彿��", ({ "bite bat", "bat" }) );
    set_race("beast");
    set_level(6);

    set("long", "����j���������A���`���w�l����G�C\n");

    set("limbs", ({ "���Y", "����", "���l", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
    //  ([ "type":"eq", "id":??, "amount":1, "p1":20, "p2":100 ]),     // ���l
    }) );

    setup();
}
