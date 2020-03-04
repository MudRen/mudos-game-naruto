#include <ansi.h>
#include <npc.h>

inherit F_SEASOLDIER;

void create()
{
    set_name("���x����", ({ "worker" }) );
    set_race("human");
    set_level(16);
    set("title",HIB"����"NOR);
    set("gender", "male");
    set("class","work_sea");
    set("camp", "police");
    set("age", 10+random(71));
    set("long", "�s�J���x�h�L�A���L���������H���A���Ф]���e�����C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"eq", "id":97, "amount":1, "p1":1, "p2":200 ]),                 // ���x�u�S���m
        ([ "type":"eq", "id":95, "amount":1, "p1":1, "p2":800 ]),                 // ���x�U
    }) );
    setup();
}
