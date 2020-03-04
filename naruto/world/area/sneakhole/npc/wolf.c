#include <ansi.h>
#include <npc.h>

void create()
{
    set_name(HIK"�j�T�j��"NOR, ({ "wolf spider", "spider", "wolf" }) );
    set_race("beast");
    set("title","���v�j��");
    set_level(26);
    set("long", "���ܪ��j�j��A�Y�O�@�����y�ۤf�����T�Y�A����o�O�K���}���j��C\n");
    set("limbs", ({ "�T�Y", "����", "����", "��L" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),       // �j��L
        ([ "type":"obj", "id":81, "amount":1, "p1":1, "p2":200 ]),        // �j��Х�
        ([ "type":"obj", "id":80, "amount":1, "p1":1, "p2":100 ]),        // �H�G
        ([ "type":"obj", "id":55, "amount":1, "p1":1, "p2":150 ]),        // �j��G�U
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // �d�J�ԤY
        ([ "type":"eq", "id":81, "amount":1, "p1":1, "p2":450 ]),         // �L�_����
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // ��O�Y
    }) );
    setup();
    add_temp("apply/attack", 30);
    set_skill("combat", 125);
    set_skill("dodge", 125);
    set_skill("parry", 125);
    set_skill("savage hit", 125);
    set_skill("heavy hit", 125);
    set_skill("continual hit", 125);
}
