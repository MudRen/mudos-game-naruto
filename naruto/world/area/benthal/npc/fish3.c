#include <npc.h>

void create()
{
    set_name("�r��", ({ "fish" }) );
    set_race("beast");
    set_level(10);
    set("long", "�������r�r�������A�s���쳣�D�`�}�֡C\n");
    set("limbs", ({ "���Y", "����", "����", "����", "���_" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 5);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"food", "id":68, "amount":1, "p1":30, "p2":100 ]),   // ����
        ([ "type":"food", "id":69, "amount":1, "p1":30, "p2":100 ]),   // ���{��
        ([ "type":"food", "id":70, "amount":1, "p1":80, "p2":100 ]),   // ���I��
        ([ "type":"food", "id":71, "amount":1, "p1":30, "p2":100 ]),   // ������
        ([ "type":"food", "id":73, "amount":1, "p1":5, "p2":100 ]),    // ���x�o
    }) );
    setup();
}
