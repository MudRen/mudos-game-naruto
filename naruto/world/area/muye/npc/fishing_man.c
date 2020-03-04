#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("����", ({ "fishing man", "man" }));
    set_race("human");
    set_level(20);
    set("age", 25+random(10));

    set("long", "�@�Ӧn��H�v���۳���b���۳������ȡC\n");

    set("chat_chance", 1);
    set("chat_msg", ({
        "���ȳݤF�X�f��D�G���ɳ��ǩ_�ǪF��...\n",
        (: command,"sweat":),
    }));

    // �]�w���������c�G (���l/����) �O�������v
    // ({ ([ "type":���O, "id":�s��, "amount":�ƶq, "p1":���l, "p2":���� ]),
    //    ([ ... ]), ([ ... ]), ... })
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":20+random(10), "p1":50, "p2":100 ]),  // �Ȥl
        ([ "type":"eq", "id":21, "amount":1, "p1":20, "p2":100 ]),     // ����M
        ([ "type":"eq", "id":7, "amount":1, "p1":20, "p2":100 ]),     // ����
        ([ "type":"eq", "id":64, "amount":1, "p1":5, "p2":100 ]),     // ���
        ([ "type":"wp", "id":15, "amount":1, "p1":20, "p2":100 ]),     // ����
    }) );

    setup();
}
