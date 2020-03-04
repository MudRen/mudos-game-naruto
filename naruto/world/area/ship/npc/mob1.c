#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("�����L", ({ "drag man", "man" }) );
    set_race("human");
    set_level(25);
    set("title",HIY"��s�s�X"NOR);
    set("gender", "male");
    set("class","little_sea");
    set("camp", "robber");
    set("age", 10+random(71));
    set("long", "��ۤ@������ˡA�S�Ƴ��w���Ӹ��h�s�s�ǵU�s�C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"eq", "id":99, "amount":1, "p1":1, "p2":300 ]),         // ��c
        ([ "type":"eq", "id":100, "amount":1, "p1":1, "p2":200 ]),        // �����
        ([ "type":"eq", "id":3, "amount":1, "p1":1, "p2":100 ]),          // �t��
        ([ "type":"eq", "id":14, "amount":1, "p1":40, "p2":100 ]),        // ����
        ([ "type":"wp", "id":57, "amount":1, "p1":30, "p2":100 ]),        // ���e
    }) );
    setup();
}
