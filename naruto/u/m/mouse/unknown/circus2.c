#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void create()
{
    set_name("小丑", ({ "circus" }) );
    set_race("human");
    set_level(12);
    set("long", "馬戲團員，為了團長的傭金而賣命。\n");
    set("age", 15+random(40));
    set("chat_chance", 5);
    set("chat_msg", ({
       CYN"小丑踩在皮球上走著。\n"NOR,
       CYN"小丑拿著火把不停丟接著。\n"NOR,
       (: command, "say 歡迎∼歡迎∼" :),
    }) );
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
         (: command, "say 這裡！":),
         (: command, "say 快欄住他！":),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":31+random(40), "p1":60, "p2":100 ]),  // 銀子
    //  ([ "type":"wp", "id":??, "amount":1, "p1":10, "p2":100 ]),    // 皮球
    //  ([ "type":"wp", "id":??, "amount":1, "p1":5, "p2":100 ]),     // 皮鞭
    }) );
    setup();
}
void init()
{
    if( this_player()->id("_HELP_BEAR_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N一見到$n便大聲叫著：「殺死牠！殺死牠！」\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
