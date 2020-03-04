#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("����", ({ "crab" }) );
    set_race("beast");
    set_level(5);
    set("age", 5+random(105));
    set("long", "�o�O�@�����ɡA�ͬ��b���䪺�F�y�W�C\n");
    set("limbs", ({ "�ɴ�", "�ɹX", "�{�l", "�ɸ}", "�ɲ�" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 6);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"food", "id":47, "amount":1, "p1":80, "p2":100 ]),    // �ɦ�
        ([ "type":"food", "id":48, "amount":1, "p1":60, "p2":100 ]),    // �ɶ�
    }) );
    setup();

}
