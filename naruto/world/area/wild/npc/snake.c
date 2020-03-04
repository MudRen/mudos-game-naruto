#include <npc.h>

void create()
{
    set_name("�D", ({ "snake" }) );
    set_race("beast");
    set_level(8);

    set("long", "�@���ʪΪ��D�C�C\n");

    set("limbs", ({ "�D�Y", "�D��", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":29, "amount":1, "p1":25, "p2":100 ]),   // �D�J
        ([ "type":"food", "id":30, "amount":1, "p1":15, "p2":100 ]),   // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":15, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":7, "p2":100 ]),   // �D��
        ([ "type":"obj", "id":108, "amount":1, "p1":1, "p2":500 ]),   // ���ѷƪO
    }) );

    setup();
}
