// write by -Acme-

#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("���H", ({ "passerby" }));
    set_race("human");
    set_level(5);
    set("age", random(50)+18);
    set("long", "�@��ܴ��q�����H�A�@�Ѧb���W�]�i�H�I���X�Q�ӡC\n");
    // �H������
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":16+random(10), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // ����
        ([ "type":"wp", "id":10, "amount":1, "p1":10, "p2":100 ]),    // �u�C
    }) );

    setup();
}
