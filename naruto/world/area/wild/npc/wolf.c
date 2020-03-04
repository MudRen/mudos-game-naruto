#include <npc.h>

void create()
{
    set_name("�T", ({ "wolf" }) );
    set_race("beast");
    set_level(10);

    set("long", "�@���ݰ_�ӫܥ��������T�C\n");

    set("limbs", ({ "�T�Y", "����", "����", "�T�L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":32, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"food", "id":33, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":57, "amount":1, "p1":15, "p2":100 ]),   // �T�}
        ([ "type":"eq", "id":58, "amount":1, "p1":13, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":59, "amount":1, "p1":15, "p2":100 ]),   // �T�}
        ([ "type":"eq", "id":60, "amount":1, "p1":15, "p2":100 ]),   // �T�Y
        ([ "type":"eq", "id":61, "amount":1, "p1":20, "p2":100 ]),  // �T��
    }) );

    setup();
}