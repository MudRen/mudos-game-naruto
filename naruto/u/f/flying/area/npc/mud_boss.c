#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("泥巴王", ({ "mud boss", "mud", "boss" }));
    set_race("human");
    set_level(30);
    
    set("long", "惡沼中的泥巴王，再25年就滿10萬歲的超老泥巴。\n"
                 );

    set("attitude", "aggressive");         // 主動攻擊

     set("age", 99985);
    set("gender", "male");

    // 守著出口
    set("guard_exit", ({ "east" }));


    setup();

    }  
int do_guard_exit(int x, int y, string exit)
{
    message_vision("$n將$N擋住。\n", this_player(), this_object());
    return 1;
}

