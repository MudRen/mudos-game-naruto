#include <npc.h>

void create()
{
    set_name("�p�ը�", ({ "rabbit" }) );
    set_race("beast");
    set_level(1);

    set("long", "�@�����ժ��ߤl�A���F���{����B�ø��C\n");

    set("limbs", ({ "�ߦ�", "����", "����", "�߻L", "����" }) );
    set("verbs", ({ "bite" }) );

    // �H������
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    set("set_drop", ({
        ([ "type":"eq", "id":78, "amount":1, "p1":10, "p2":100 ]),     // ÷�l
          ([ "type":"eq", "id":79, "amount":1, "p1":5, "p2":100 ]),     // �ߧ���
    }) );

    setup();
}
