#include <npc.h>

void create()
{
    set_name("�j�ѹ�", ({ "big mouse", "mouse" }) );
    set_race("beast");
    set_level(4);

    set("long", "�@��ż�������j�ѹ��C\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":35, "amount":1, "p1":80, "p2":100 ]),   // ����
        ([ "type":"food", "id":36, "amount":1, "p1":80, "p2":100 ]),   // ���}
        ([ "type":"food", "id":37, "amount":1, "p1":80, "p2":100 ]),   // ����
    }) );

    setup();
}