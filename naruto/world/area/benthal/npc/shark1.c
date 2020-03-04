#include <npc.h>

void create()
{
    set_name("���T", ({ "tiger shark", "shark" }) );
    set_race("beast");
    set_level(16);
    set("long", "����������T���A����F���������C\n");
    set("limbs", ({ "�T�Y", "����", "����", "�T��", "�T�_" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"food", "id":75, "amount":1, "p1":80, "p2":100 ]),   // �T����
        ([ "type":"obj", "id":104, "amount":1, "p1":20, "p2":100 ]),   // �T��
        ([ "type":"obj", "id":103, "amount":1, "p1":10, "p2":100 ]),   // �T����
    }) );
    setup();
    add_temp("apply/attack", 30);
    add_temp("apply/evade", 50);
}
