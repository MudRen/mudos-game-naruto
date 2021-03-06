#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void create()
{
    set_name("馬戲團長", ({ "circus man", "man" }) );
    set_race("human");
    set_level(16);
    set("long", "壞心的團長，在鯨魚島抓了不少動物給旅客觀賞賺錢。\n");
    set("age", 50);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
       CYN"馬戲團長面帶微笑地說﹕歡迎∼歡迎光臨阿。\n"NOR,
       (: command, "say 我們有很多動物可供觀賞喔∼" :),
       (: command, "say 最近還抓到一隻鯨魚島才有的兇暴狐熊喔！" :),
    }) );
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
         (: command, "say 不要放走我的動物阿！":),
         (: command, "say 快欄住他！":),
         (: command, "say 獵人先生這裡阿！" :),
         (: command, "kill bear" :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":61+random(40), "p1":60, "p2":100 ]),  // 銀子
    //  ([ "type":"wp", "id":??, "amount":1, "p1":20, "p2":100 ]),    // 皮球
    //  ([ "type":"wp", "id":??, "amount":1, "p1":10, "p2":100 ]),    // 皮鞭
    }) );
    setup();
}
void init()
{
    if( this_player()->id("_HELP_BEAR_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N一見到$n便大聲叫著：「牠在這裡，不能活抓也要殺死！」\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
