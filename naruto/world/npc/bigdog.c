/* bigdog.c
   write by -Acme-
*/

#include <ansi.h>
#include <npc.h>

void create()
{
    set_name("�j����", ({ "big dog", "dog" }) );
    set_race("beast");
    set_level(2);

    set("long", "�@��ż�����������A�L���ٺw�ۤf���C\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    // �H������
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    // �]�w���������c�G (���l/����) �O�������v
    // ({ ([ "type":���O, "id":�s��, "amount":�ƶq, "p1":���l, "p2":���� ]),
    //    ([ ... ]), ([ ... ]), ... })
    set("set_drop", ({
        ([ "type":"eq", "id":5, "amount":1, "p1":10, "p2":100 ]),     // ÷�l
    }) );

    setup();
    
    // �d�z
    set_attr("str", 10);
    set_attr("con", 10);
    set_attr("dex", 10);
    set_attr("int", 10);
    set_temp("apply/attack", -5);         // �����O�q
    set_temp("apply/defend", -5);         // ���m�O�q
    set_temp("apply/exact", -5);          // �R���v
    set_temp("apply/evade", -5);          // �j�ײv
    set_temp("apply/intimidate", -5);     // ������O
    set_temp("apply/wittiness", -5);      // ���m��O
}