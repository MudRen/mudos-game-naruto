#include <npc.h>

void create()
{
    set_name("��������", ({ "mutation cockroach", "cockroach" }) );
    set_race("beast");
    set_level(7);

    set("long", "�@�����ߪ����������C\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"obj", "id":25, "amount":1, "p1":80, "p2":100 ]),   // ����Ĳ��
        ([ "type":"food", "id":34, "amount":1, "p1":60, "p2":100 ]),   // �����Z
        ([ "type":"obj", "id":26, "amount":1, "p1":80, "p2":100 ]),   // �����}
    }) );

    setup();
}