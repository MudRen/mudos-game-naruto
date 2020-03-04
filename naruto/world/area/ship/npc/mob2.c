#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("�����L", ({ "search man", "man" }) );
    set_race("human");
    set_level(28);
    set("title",HIY"��s�s�X"NOR);
    set("gender", "male");
    set("class","little_sea");
    set("camp", "robber");
    set("age", 10+random(71));
    set("long", "�Y�W�a�۷��l�ߡA�����|�B�i�檺�H�A���G�b��������C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"eq", "id":70, "amount":1, "p1":10, "p2":100 ]),        // ���l��
        ([ "type":"wp", "id":12, "amount":1, "p1":20, "p2":100 ]),        // �尨�j�M
        ([ "type":"wp", "id":40, "amount":1, "p1":1, "p2":100 ]),         // ���ۼC
    }) );
    setup();
}
