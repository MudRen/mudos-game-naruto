#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�C��", ({ "traveler" }) );
    set_race("human");
    set_level(7);
    set("age", 18+random(60));
    set("long", "�M�{�Ө��H���q�C�����ȫȡA�y�W�����F���e�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        "�C�ȱ�ۮ���A���G�R�W�F�o���g�a�C\n",
        (: command, "say �b�o�̥i�H�o��R�����𮧡C":),
        (: command, "say �o�Ӧa�����үu�u�����I":),
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":30+random(10), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"obj", "id":30, "amount":1, "p1":3, "p2":100 ]),    // �¥��U
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // ����
        ([ "type":"wp", "id":10, "amount":1, "p1":10, "p2":100 ]),    // �ñ�
    }) );
    setup();
}
int accept_fight(object ob)
{
    do_chat(({ 
        (: command, "shake" :),
        (: command, "say �[�����Ӥ��ΤF�A�����ɶ����[�C" :),
    }));
    return 0;
}
