// man.c

#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("甘寧老師", ({ "eccentric" }) );
        set_race("human");
        set_level(20);
        set("age", 70);
        set("long", "一位詭異的老頭\n");

    // 隨機移動
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));
        setup();
        carry_money("gold", 2);
//      carry_object("/obj/area/obj/cloth")->wear();
//      carry_object("/obj/area/obj/shortsword")->wield();
}

