#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�ɱN", ({ "crab general", "general" }) );
    set_race("beast");
    set_level(12);
    set("age", 5+random(105));
    set("long", "���ɤj�N�A���ɪ��i�{�e�����X�V�A�ܫ¡C\n");
    set("limbs", ({ "�ɴ�", "�ɹX", "�{�l", "�ɸ}", "����", "���X" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance", 6);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 3);
    set("chat_msg_combat", ({
        CYN"�ɱN���R�ۥ��X�V�A�ܫ¡C\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"food", "id":44, "amount":1, "p1":50, "p2":100 ]),  // �ɦץլ�
        ([ "type":"eq", "id":75, "amount":1, "p1":30, "p2":100 ]),    // �ɴ�
        ([ "type":"wp", "id":23, "amount":1, "p1":10, "p2":100 ]),    // �ɹX
    }) );
    setup();

    // �W�j
    add_temp("apply/armor", 50);
}
