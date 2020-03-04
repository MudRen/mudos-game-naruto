// write by -Acme-

#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�^��", ({ "beggar" }));
    set_race("human");
    set_level(5);
    set("title", "����");
    set("nickname", "�s�Ƥl");
    set("age", random(50)+10);
    set("long", "�@���ۯ}�}����^���A���Y�������ɪ����o����A�O�H�@���C\n");
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
    }) );

    setup();

    // �d�z
    set_attr("str", 15);
    set_attr("con", 15);
    set_attr("dex", 15);
    set_attr("int", 15);
    set_temp("apply/attack", -3);         // �����O�q
    set_temp("apply/defend", -3);         // ���m�O�q
    set_temp("apply/exact", -3);          // �R���v
    set_temp("apply/evade", -3);          // �j�ײv
    set_temp("apply/intimidate", -3);     // ������O
    set_temp("apply/wittiness", -3);      // ���m��O
}
