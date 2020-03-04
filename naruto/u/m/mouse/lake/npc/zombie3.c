#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�G�ͤ�", ({ "zombie king", "king" }) );
    set_race("beast");
    set_level(20);
    set("age", 450);
    set("nickname", "���å�");
    set("long", "�ΪέD�D���G�͡A�ݰ_�Ӥ��L�G�������ߡC\n");
    set("limbs", ({ "�ͭ�", "�ͨ�", "�ͨ�", "�ͻL", "���u", "�ͤ�", "�ͨ{" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance_combat", 5);          // �԰��ʧ@
    set("chat_msg_combat", ({
        CYN"�G�ͤ�����ۨ��鲾�ʡA���G�Q���}�o�̡C\n"NOR,
        CYN"�G�ͪ��}�{�������y�X�ͤ��C\n"NOR,
        CYN"�G�͵o�X�u���㫢���v�����n�C\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":100+random(300), "p1":80, "p2":100 ]), // �Ȥl
        ([ "type":"eq", "id":5, "amount":1+random(1), "p1":40, "p2":100 ]),       // ÷�l
        ([ "type":"eq", "id":4, "amount":1, "p1":30, "p2":100 ]),                 // �ֱa
        ([ "type":"wp", "id":10, "amount":1, "p1":10, "p2":100 ]),                // �ñ�
        ([ "type":"wp", "id":4, "amount":1, "p1":5, "p2":100 ]),                  // ���ޤM
        ([ "type":"obj", "id":47, "amount":1, "p1":20, "p2":100 ]),               // �Ũ�
    }) );
    setup();
    // �W�j
    set_temp("apply/armor", 200);            // ���m�O�q
    set_stat_current("hp", 1500);            // ��O
    set_stat_maximum("hp", 1500);            // �̤j��
}
