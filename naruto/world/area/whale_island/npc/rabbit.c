#include <npc.h>

void create()
{
    set_name("小白兔", ({ "rabbit" }) );
    set_race("beast");
    set_level(1);

    set("long", "一隻雪白的兔子，活靈活現的到處亂跳。\n");

    set("limbs", ({ "兔耳", "身體", "腹部", "兔腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );

    // 隨機移動
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    set("set_drop", ({
        ([ "type":"eq", "id":78, "amount":1, "p1":10, "p2":100 ]),     // 繩子
          ([ "type":"eq", "id":79, "amount":1, "p1":5, "p2":100 ]),     // 兔尾巴
    }) );

    setup();
}
