#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�G��", ({ "zombie" }) );
    set_race("beast");
    set_level(16);
    set("age", 450);
    set("nickname", "�k��");
    set("long", "�q�o���W�������G�ꪺ��A�i�H�ݥX�O�@��k�ġC\n");
    set("limbs", ({ "�ͭ�", "�ͨ�", "�ͨ�", "�ͻL", "���u", "�ͤ�" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // �D�ʧ���
    set("chat_chance_combat", 5);          // �԰��ʧ@
    set("chat_msg_combat", ({
        NOR"�G�ͫիի�D�R"HIG"�D�H����D�H����\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":100+random(150), "p1":70, "p2":100 ]), // �Ȥl
        ([ "type":"eq", "id":5, "amount":1+random(1), "p1":40, "p2":100 ]),       // ÷�l
        ([ "type":"eq", "id":4, "amount":1, "p1":30, "p2":100 ]),                 // �ֱa
        ([ "type":"obj", "id":46, "amount":1, "p1":20, "p2":100 ]),               // ����
    }) );
    setup();
    // �W�j
    add_temp("apply/attack", 30);
    add_temp("apply/armor", 50);
}
