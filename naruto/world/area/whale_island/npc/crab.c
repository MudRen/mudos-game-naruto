#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�p����", ({ "small crab", "crab" }) );
    set_race("beast");
    set_level(3);
    set("age", 5+random(105));
    set("long", "�o�O�@���p���ɡA�ͬ��b���䪺�F�y�W�C\n");
    set("limbs", ({ "�ɴ�", "�ɹX", "�{�l", "�ɸ}", "�ɲ�" }) );
    set("verbs", ({ "bite" }) );
    set("set_drop", ({
        ([ "type":"food", "id":47, "amount":1, "p1":80, "p2":100 ]),    // �ɦ�
        ([ "type":"food", "id":48, "amount":1, "p1":60, "p2":100 ]),    // �ɶ�
            ([ "type":"obj", "id":87, "amount":1, "p1":1, "p2":500 ]),    // ���ѱ���
    }) );
    setup();

}
