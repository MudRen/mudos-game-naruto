#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void create()
{
    set_name("獵人", ({ "hunter" }) );
    set_race("human");
    set_level(15);
    set("long", "在森林中危法抓取狐熊的可惡獵人。\n");
    set("age", 20+random(30));
    set("gender", "male");
    set("attitude", "aggressive");
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
         CYN"獵人氣的直跳腳。\n"NOR,
         (: command, "say 可惡的狐熊！又把我的獸夾弄壞了。":),
         (: command, "say 走開！別擋路！" :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":51+random(10), "p1":50, "p2":100 ]),  // 銀子
        ([ "type":"obj", "id":30, "amount":1, "p1":5, "p2":100 ]),    // 麻布袋
        ([ "type":"wp", "id":10, "amount":1, "p1":10, "p2":100 ]),    // 藤條
    //  ([ "type":"obj", "id":??, "amount":1, "p1":10, "p2":100 ]),   // 捕獸夾
    //  ([ "type":"wp", "id":??, "amount":1, "p1":5, "p2":100 ]),     // 來福槍
    }) );
    setup();
}
