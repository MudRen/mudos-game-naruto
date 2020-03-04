#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("魅影(改)", ({ "mei ying", "mei", "ying" }));
    set_race("human");
    set_level(70);
    
    set("long", "魅影城城主，一股至高無上的氣魄無形中散佈整個房中。\n"
                 );

    set("title", "仿•城主");

    set("age", 3962);
    set("gender", "male");

    setup();

    carry_object("/u/f/flying/wp/blade")->wield("twohanded");
    carry_object("/u/f/flying/eq/beq/bpants")->wear();
    carry_object("/u/f/flying/eq/beq/bwrist")->wear();
    carry_object("/u/f/flying/eq/beq/barmor")->wear();
    carry_object("/u/f/flying/eq/beq/bcloth")->wear(); 
    carry_object("/u/f/flying/eq/beq/bboots")->wear();
    carry_object("/u/f/flying/eq/beq/bgloves")->wear();
    carry_object("/u/f/flying/eq/beq/bleg")->wear();
    // 基本技能
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("combat", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 200);
}

