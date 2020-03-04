#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("老婆婆", ({ "old woman", "woman" }));
    set_race("human");
    set_level(5);
    
    set("long", "老婆婆起來愁眉苦臉的，好像有什麼煩惱一樣。\n");

    set("age", 70);
    set("gender", "female");
    
    // 一般時動作
    set("chat_chance", 1);
    set("chat_msg", ({
        (: command, "say 唉！後院的雜草叢生，不知要拔到什麼時候.." :),
    }) );

    setup();
}
