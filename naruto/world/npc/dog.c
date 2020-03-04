/* dog.c
   write by -Acme-
*/

#include <npc.h>

void create()
{
    set_name("����", ({ "dog" }) );
    set_race("beast");
    set_level(1);

    set("long", "�@��ż�����������A�L���ٺw�ۤf���C\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    // �H������
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    set("set_drop", ({
        ([ "type":"eq", "id":5, "amount":1, "p1":10, "p2":100 ]),     // ÷�l
    }) );

    setup();
    
    // �d�z
    set_attr("str", 5);
    set_attr("con", 5);
    set_attr("dex", 5);
    set_attr("int", 5);
    set_temp("apply/attack", -10);         // �����O�q
    set_temp("apply/defend", -10);         // ���m�O�q
    set_temp("apply/exact", -10);          // �R���v
    set_temp("apply/evade", -10);          // �j�ײv
    set_temp("apply/intimidate", -10);     // ������O
    set_temp("apply/wittiness", -10);      // ���m��O
}