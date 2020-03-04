#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("���L", ({ "shrimp soldier", "soldier" }) );
    set_race("beast");
    set_level(10);
    set("age", 5+random(105));
    set("long", "�s���p�L�A�ɱ`�b�|�P��Ӵ�h�n���b���ޡC\n");
    set("limbs", ({ "����", "���X", "�{�l", "���}", "����", "����" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance", 6);                 // �ʧ@�t�v
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 3);          // �԰��t�v
    set("chat_msg_combat", ({
        CYN"���L�������R�۪w�w�C\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"food", "id":46, "amount":1, "p1":50, "p2":100 ]),  // �s���F��
        ([ "type":"eq", "id":77, "amount":1, "p1":30, "p2":100 ]),    // ����
    }) );
    setup();

    // �W�j
    add_temp("apply/armor", 50);
}
