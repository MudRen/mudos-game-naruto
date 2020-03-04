#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�G��", ({ "zombie" }) );
    set_race("beast");
    set_level(15);
    set("age", 100+random(500));
    set("long", "�����G�ꪺ����A�ݤ[�F���I���ߡC\n");
    set("limbs", ({ "�ͭ�", "�ͨ�", "�ͨ�", "�ͻL", "���u", "�ͤ�" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance", 5);                 // �԰��ʧ@
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 3);          // �԰��t�v
    set("chat_msg_combat", ({
        CYN"�G�͵o�X�u������v�����n�C\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":50+random(100), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"eq", "id":5, "amount":1+random(1), "p1":40, "p2":100 ]),       // ÷�l
        ([ "type":"eq", "id":4, "amount":1, "p1":30, "p2":100 ]),                 // �ֱa
    }) );
    setup();
    // �W�j
    set_temp("apply/attack", 30);            // �����O�q
    set_temp("apply/armor", 180);            // ���m�O�q
    set_stat_current("hp", 900);             // ��O
    set_stat_maximum("hp", 900);             // �̤j��
}
