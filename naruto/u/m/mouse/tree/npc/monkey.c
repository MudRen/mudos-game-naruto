#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�U�l", ({ "monkey" }));
    set_race("beast");
    set_level(15);
    set("age", 10+random(20));

    set("long", "�@����H���S���ķN���j�U�l�C\n");

    set("limbs", ({ "�U�Y", "����", "�{�l", "�U�u", "����", "�U�I", "����" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 5);
    set("chat_msg", ({
        CYN"�U�l�s�s���s�ۡC\n"NOR,
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"eq", "id":73, "amount":1, "p1":60, "p2":100 ]),              // �U��
        ([ "type":"food", "id":43, "amount":1+random(1), "p1":50, "p2":100 ]),  // �U�x
        ([ "type":"food", "id":42, "amount":1, "p1":20, "p2":100 ]),            // �U��
        ([ "type":"eq", "id":70, "amount":1, "p1":5, "p2":100 ]),               // ���l��
        ([ "type":"obj", "id":36, "amount":1, "p1":1, "p2":100 ]),              // �j�Ѧa��
    }) );
    setup();
    set_temp("apply/armor", 2);            // ���m�O�q
}
