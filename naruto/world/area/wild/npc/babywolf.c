#include <npc.h>

void create()
{
    set_name("���T", ({ "baby wolf", "wolf" }) );
    set_race("beast");
    set_level(1);

    set("long", "�@���X�ͤ��L�X�Ӥ몺�p�T�A�ݰ_�ӫܥi�R�C\n");

    set("limbs", ({ "�T�Y", "����", "����", "�T�L", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":32, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"food", "id":33, "amount":1, "p1":80, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":57, "amount":1, "p1":5, "p2":100 ]),   // �T�}
        ([ "type":"eq", "id":58, "amount":1, "p1":3, "p2":100 ]),   // �T��
        ([ "type":"eq", "id":59, "amount":1, "p1":5, "p2":100 ]),   // �T�}
        ([ "type":"eq", "id":60, "amount":1, "p1":5, "p2":100 ]),   // �T�Y
        ([ "type":"eq", "id":61, "amount":1, "p1":10, "p2":100 ]),  // �T��
    }) );

    setup();
}
