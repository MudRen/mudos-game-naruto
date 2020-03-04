#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIW"�j���T"NOR, ({ "white shark", "shark" }) );
    set_race("beast");
    set_level(21);
    set("age", random(100) + 5);
    set("long", "�j���T���A�D�`�㦳�M�I�ʡC\n");
    set("limbs", ({ "�T�Y", "����", "����", "�T��", "�T�_" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"food", "id":75, "amount":1, "p1":80, "p2":100 ]),   // �T����
        ([ "type":"obj", "id":104, "amount":1, "p1":30, "p2":100 ]),   // �T��
        ([ "type":"obj", "id":103, "amount":1, "p1":20, "p2":100 ]),   // �T����
    }) );
    setup();
    add_temp("apply/attack", 50);
    add_temp("apply/armor", 30);
}
