#include <npc.h>
#include <ansi.h>
#include "wp.h"

void do_fight()
{
    mapping cnd = ([]);

    if( this_object()->query_condition("bladewolf") != 0 ) return;

    message_vision(HIR"\n$N眼光泛紅，血色迅速佈滿整個眼上，顏面青筋曝露，完全爆發出野獸般的獸性！\n\n"NOR, this_object());

    cnd["name"] = RED"狂暴"NOR;
    cnd["duration"] = 600;
    cnd["intimidate"] = 300;
    cnd["evade"] = 0;

    this_object()->damage_stat("mp", 10, this_object());
    this_object()->set_condition("bladewolf", cnd);
    return;
}
void create()
{
    set_name("土著狂戰士", ({ "aborigines sacrier", "sacrier" }) );
    set_level(50);
    set_race("human");
    set("gender", "male");
    set("attitude", "aggressive");
    set("wp_number", 3);
    set("age", 15+random(41));
    set("nickname",HIR"嗜血"NOR);
    set("long", "穿著簡陋的土著，露出一身可怕的肌肉，臉上不停地抽動著，口中吐\n"
                "出白色的氣息，有如蓄勢待發的野獸。他就是傳說中野獸本能比人類\n"
                "理性更發達，有時還能完全發揮獸性的兇暴狂戰士。\n");
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
    add_temp("apply/hp", random(300));
    set_temp("apply/exact", -(50 + random(101)));
    carry_object(__DIR__"wp/lance.c")->wield("twohanded");
    call_out("die_1", 120+random(240), this_object());
    do_heal();
}

void die_1()
{
    message_vision(GRN"$N看了一看四周，又躲回叢林中了。\n"NOR, this_object());
    destruct(this_object());
    return;
}
