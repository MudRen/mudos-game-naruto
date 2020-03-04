#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("����", ({ "shell commander", "commander" }) );
    set_race("beast");
    set_level(12);
    set("age", 5+random(105));
    set("long", "���ߤ��ӡA�b�i�������������j�ï]���H�ݤF���y�f���C\n");
    set("limbs", ({ "����", "����", "�ï]" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance", 3);                 // �ʧ@�t�v
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 3);          // �԰��t�v
    set("chat_msg_combat", ({
        CYN"���Ӱ��������}�~�߳z��C\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"food", "id":45, "amount":1, "p1":50, "p2":100 ]),  // ��Į
        ([ "type":"eq", "id":76, "amount":1, "p1":30, "p2":100 ]),    // ����
        ([ "type":"obj", "id":44, "amount":1, "p1":5, "p2":100 ]),    // ���j�ï]
    }) );
    setup();

    // �W�j
    add_temp("apply/armor", 50);
}
