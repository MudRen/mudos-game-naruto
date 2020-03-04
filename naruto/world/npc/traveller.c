//traveller.c

#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�L����", ({ "traveller" }) );
    set("unit", "��");
    set("gender", "male");
    set_level(6);
    set("age", 18+random(60));
    set("long", "�@����^�^�A���y�������L���ȡA�@���l�ˡA���G�H�ɤS�n�W���h�C\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        "�L���ȳݤF�X�f��D�G�I �I... �n�֡A�u���C\n",
        "�L���Ȧ��G�֪������X�ܨӤF�C\n",
        (: command,"sweat":),
        (: random_move :),
    }));

    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":21+random(10), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"obj", "id":30, "amount":1, "p1":3, "p2":100 ]),  // �¥��U
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // ����
        ([ "type":"wp", "id":10, "amount":1, "p1":10, "p2":100 ]),    // �u�C
    }) );

    setup();
}

int accept_fight(object ob)
{
    do_chat("�L�������F����l�W���������D�G�u��ԣ�A���ֲ�½�F�٥��I�v\n");
    return 0;
}
