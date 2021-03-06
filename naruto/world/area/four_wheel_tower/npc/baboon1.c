#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("狒狒", ({ "baboon" }) );
    set_level(22);
    set_race("human");
    if( random(2) == 1) set("gender", "male");
    else set("gender", "female");
    set("limbs", ({ "猴頭", "猴臂", "猴尾", "胸口", "猴腳", "肩膀", "腰部" }) );
    set("age", 15+random(80));
    set("long", "尖牙利嘴的猴子類生物，看起來比一般的猴子大隻。\n");
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":151, "amount":random(5)+1, "p1":80, "p2":100 ]),   // 廢土
        ([ "type":"obj", "id":152, "amount":random(15)+1, "p1":80, "p2":100 ]),  // 塵埃
        ([ "type":"obj", "id":148, "amount":random(2)+1, "p1":30, "p2":100 ]),   // 炎灰
        ([ "type":"obj", "id":158, "amount":1, "p1":10, "p2":100 ]),             // 燒土
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

    if( killer->query_level() - 10 <= this_object()->query_level() && killer->query_point("learn") < 2000000 ) {
        tell_object(killer, HIR"\n你殺死了"+this_object()->query("name")+"而額外獲得了 "HIY+i+HIR" 點學點。\n"NOR);
        killer->add_point("learn", i);
    }
    ::die();
    return;
}