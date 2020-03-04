#include <npc.h>

void create()
{
    set_name("���ܦa��", ({ "mutation earth mouse", "mouse" }) );
    set_race("beast");
    set_level(8);
    set("long", "�@���ΪέD�D�A�զ��S�O�j�����ܦa���C\n");
    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance", 5);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"food", "id":35, "amount":1, "p1":80, "p2":100 ]),   // ����
        ([ "type":"food", "id":36, "amount":1, "p1":80, "p2":100 ]),   // ���}
        ([ "type":"food", "id":37, "amount":1, "p1":80, "p2":100 ]),   // ����
        ([ "type":"food", "id":56, "amount":1, "p1":15, "p2":100 ]),   // ����
    }) );
    setup();
}
