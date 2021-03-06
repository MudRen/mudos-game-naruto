#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("遊客", ({ "traveler" }) );
    set_race("human");
    set_level(7);
    set("age", 18+random(60));
    set("long", "專程來到鯨魚島遊玩的旅客，臉上掛滿了笑容。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        "遊客望著海邊，似乎愛上了這片土地。\n",
        (: command, "say 在這裡可以得到充分的休息。":),
        (: command, "say 這個地方環境真優美阿！":),
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":30+random(10), "p1":50, "p2":100 ]),  // 銀子
        ([ "type":"obj", "id":30, "amount":1, "p1":3, "p2":100 ]),    // 麻布袋
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // 布衣
        ([ "type":"wp", "id":10, "amount":1, "p1":10, "p2":100 ]),    // 藤條
    }) );
    setup();
}
int accept_fight(object ob)
{
    do_chat(({ 
        (: command, "shake" :),
        (: command, "say 觀光都來不及了，哪有時間打架。" :),
    }));
    return 0;
}
