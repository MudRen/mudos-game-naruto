#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�~��", ({ "inhabitant" }) );
    set_race("human");
    set_level(5);
    set("long", "�H���q������A�ͬ��w�h�A�y�W�`�O���a���e�C\n");
    set("age", 5+random(80));
    set("chat_chance", 6);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":16+random(10), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // ����
        ([ "type":"wp", "id":10, "amount":1, "p1":10, "p2":100 ]),    // �ñ�
    }) );
    setup();
}
