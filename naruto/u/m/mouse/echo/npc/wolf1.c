#include <npc.h>

void create()
{
    set_name("幼山狼", ({ "baby wolf", "wolf" }) );
    set_race("beast");
    set_level(1);
    set("long", "一隻出生不過幾個月的山狼，一直努力的叫出喵喵聲。\n");
    set("limbs", ({ "狼頭", "身體", "腹部", "狼腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        (: command, "cat" :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":79, "amount":1, "p1":10, "p2":100 ]),    // 狼牙
        ([ "type":"food", "id":32, "amount":1, "p1":80, "p2":100 ]),   // 狼心
        ([ "type":"food", "id":33, "amount":1, "p1":80, "p2":100 ]),   // 狼肺
        ([ "type":"eq", "id":57, "amount":1, "p1":5, "p2":100 ]),      // 狼腳
        ([ "type":"eq", "id":58, "amount":1, "p1":3, "p2":100 ]),      // 狼皮
        ([ "type":"eq", "id":59, "amount":1, "p1":5, "p2":100 ]),      // 狼腳
        ([ "type":"eq", "id":60, "amount":1, "p1":5, "p2":100 ]),      // 狼頭
        ([ "type":"eq", "id":61, "amount":1, "p1":10, "p2":100 ]),     // 狼尾
    }) );
    setup();
}
