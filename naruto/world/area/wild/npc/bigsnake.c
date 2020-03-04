#include <npc.h>

void create()
{
    set_name("�j�D", ({ "big snake", "snake" }) );
    set_race("beast");
    set_level(13);

    set("long", "�@���S���S�ʪ��j�D�C\n");

    set("limbs", ({ "�D�Y", "�D��", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":29, "amount":1, "p1":30, "p2":100 ]),   // �D�J
        ([ "type":"food", "id":30, "amount":1, "p1":20, "p2":100 ]),   // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":20, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":15, "p2":100 ]),   // �D��
    }) );

    setup();
}
