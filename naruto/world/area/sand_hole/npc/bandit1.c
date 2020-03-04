#include <npc.h>
#include <ansi.h>
#include "enhance.h"

inherit F_FIGHTER;

void create()
{
    set_name("�C�űj�s", ({ "bandit" }) );
    set_level(25);
    set_race("human");
    if( random(2) == 1) {
        set("gender", "male");
    } else {
        set("gender", "female");
    }
    set("chat_chance", 20);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("camp", "sand_bandit");
    set("age", 15+random(41));
    set("title",YEL"�a�U�F��"NOR);
    set("long", "�S�Ʈ��۪��M��B�ó}��H�·СA�@�ݴN���D�O�̤U�Ū��j�s�C\n");
    set("item_drop", "/world/area/sand_hole/npc/wp/long_blade.c");
    set("molecule", 1);            // ���l
    set("denominator", 300);       // ����
    set("set_drop", ({
        ([ "type":"wp", "id":34, "amount":1, "p1":1, "p2":100 ]),                  // �K�M
        ([ "type":"obj", "id":29, "amount":10 + random(200), "p1":80, "p2":100 ]), // �Ȥl
    }) );
    setup();
    carry_object(__DIR__"wp/long_blade.c")->wield("righthand");
    add_temp("apply/armor", 100);
}
