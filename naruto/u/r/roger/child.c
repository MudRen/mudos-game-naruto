// write by -Acme-

#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�p��", ({ "child" }));
    set_race("human");
    set_level(3);
    set("age", 6+random(10));
    set("long", "�@�Ӭy�ۻ�����p�ġA�����b�����o����ż�����C\n");

    // �H������
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    // �]�w���������c�G (���l/����) �O�������v
    // ({ ([ "type":���O, "id":�s��, "amount":�ƶq, "p1":���l, "p2":���� ]),
    //    ([ ... ]), ([ ... ]), ... })
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":random(10)+1, "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // ����
        ([ "type":"wp", "id":9, "amount":1, "p1":10, "p2":100 ]),     // �ڽ�
    }) );

    setup();

    // �d�z
    set_attr("str", 12);
    set_attr("con", 12);
    set_attr("dex", 12);
    set_attr("int", 12);
    set_temp("apply/attack", -5);         // �����O�q
    set_temp("apply/defend", -5);         // ���m�O�q
    set_temp("apply/exact", -5);          // �R���v
    set_temp("apply/evade", -5);          // �j�ײv
    set_temp("apply/intimidate", -5);     // ������O
    set_temp("apply/wittiness", -5);      // ���m��O
}
