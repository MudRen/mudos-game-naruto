#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("鋼蛋", ({ "gan dan", "dan" }));
    set_race("human");
    set_level(70);
    
    set("long", "鋼蛋一族中最強的鋼蛋\n"
                 );

    set("title", "黃金鋼蛋");

    set("age", 26);
    set("gender", "male");

    setup();

    // 基本技能
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("combat", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 200);
}


