#include <npc.h>
#include <ansi.h>
#include "fire_sk.h"

void create()
{
    set_name("大金剛", ({ "kingkong" }) );
    set_level(55);
    set_race("human");
    if( random(2) == 1) set("gender", "male");
    else set("gender", "female");
    set("limbs", ({ "猴頭", "猴臂", "猴尾", "胸口", "猴腳", "肩膀", "腰部" }) );
    set("age", 15+random(80));
    set("long", "身材強壯的猿猴，因為太過巨大，所以人們給了他一個金剛的稱呼。\n");
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
        ([ "type":"obj", "id":151, "amount":random(20)+1, "p1":80, "p2":100 ]),  // 廢土
        ([ "type":"obj", "id":152, "amount":random(30)+1, "p1":80, "p2":100 ]),  // 塵埃
        ([ "type":"obj", "id":153, "amount":random(5)+1, "p1":80, "p2":100 ]),   // 爛果
        ([ "type":"obj", "id":156, "amount":random(10)+1, "p1":80, "p2":100 ]),  // 碎石
        ([ "type":"obj", "id":148, "amount":random(15)+1, "p1":30, "p2":100 ]),  // 炎灰
        ([ "type":"obj", "id":158, "amount":random(5)+1, "p1":10, "p2":100 ]),   // 燒土
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
    // 寵物殺死算主人的
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    i = query_level()*5 - random(query_level());

    if( killer->query_level() - 10 <= this_object()->query_level() && killer->query_point("learn") < 5000000 ) {
        tell_object(killer, HIR"\n你殺死了"+this_object()->query("name")+"而額外獲得了 "HIY+i+HIR" 點學點。\n"NOR);
        killer->add_point("learn", i);
    }
    ::die();
    return;
}