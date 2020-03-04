#include <npc.h>
#include <ansi.h>
#include "fire_sk.h"

void create()
{
    set_name("����", ({ "red ape", "ape" }) );
    set_level(42);
    set_race("human");
    if( random(2) == 1) set("gender", "male");
    else set("gender", "female");
    set("limbs", ({ "�U�Y", "�U�u", "�U��", "�ݤf", "�U�}", "�ӻH", "�y��" }) );
    set("age", 15+random(80));
    set("long", "���q�q����U�A�]���O�@��ҥH���W�C�@�ڤ򳣬O�`����C\n");
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 35);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":151, "amount":1+random(15), "p1":80, "p2":100 ]),  // �o�g
        ([ "type":"obj", "id":152, "amount":1+random(25), "p1":80, "p2":100 ]),  // �ЮJ
        ([ "type":"obj", "id":153, "amount":1+random(3), "p1":80, "p2":100 ]),   // ��G
        ([ "type":"obj", "id":156, "amount":1+random(10), "p1":80, "p2":100 ]),  // �H��
        ([ "type":"obj", "id":148, "amount":1+random(10), "p1":30, "p2":100 ]),  // ����
        ([ "type":"obj", "id":158, "amount":1+random(3), "p1":10, "p2":100 ]),   // �N�g
    }) );
    setup();
    add_temp("apply/attack", 50);
}

void die()
{
    object enemy, killer;
    int i;
    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        ::die();
        return;
    }
    // �d��������D�H��
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    i = query_level()*5 - random(query_level());

    if( killer->query_level() - 10 <= this_object()->query_level() && killer->query_point("learn") < 4000000 ) {
        tell_object(killer, HIR"\n�A�����F"+this_object()->query("name")+"���B�~��o�F "HIY+i+HIR" �I���I�C\n"NOR);
        killer->add_point("learn", i);
    }
    ::die();
    return;
}