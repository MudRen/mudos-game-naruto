#include <npc.h>

void create()
{
    set_name("�p�D", ({ "small snake", "snake" }) );
    set_race("beast");
    set_level(5);

    set("long", "�@���b�����u���p�D�C\n");

    set("limbs", ({ "�D�Y", "�D��", "����" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // �D�ʧ���

    set("set_drop", ({
        ([ "type":"food", "id":29, "amount":1, "p1":20, "p2":100 ]),   // �D�J
        ([ "type":"food", "id":30, "amount":1, "p1":10, "p2":100 ]),   // �D�x
        ([ "type":"obj", "id":24, "amount":1, "p1":10, "p2":100 ]),   // �D��
        ([ "type":"wp", "id":14, "amount":1, "p1":3, "p2":100 ]),   // �D��
    }) );

    setup();
}
