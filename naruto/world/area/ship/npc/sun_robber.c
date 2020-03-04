#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("���o", ({ "robber" }) );
    set_race("human");
    set_level(15);
    set("title", HIR"�T���"NOR);
    if( random(2) == 0 ) {
        set("gender", "male");
    } else {
        set("gender", "female");
    }
    set("class", "little_sea");
    set("camp", "robber");
    set("age", 10+random(51));
    set("long", "���Y�鸣������A�ݰ_�ӨS����j���C\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"wp", "id":55, "amount":1, "p1":50, "p2":100 ]),     // �s�;ԤM
        ([ "type":"wp", "id":45, "amount":1, "p1":30, "p2":100 ]),     // ��C
        ([ "type":"eq", "id":49, "amount":1, "p1":1, "p2":800 ]),      // ���򨭦�
        ([ "type":"eq", "id":32, "amount":1, "p1":40, "p2":100 ]),     // �j�K�U
    }) );
    setup();
}
