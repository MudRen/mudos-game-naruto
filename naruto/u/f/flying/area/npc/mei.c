#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�y�v", ({ "mei ying", "mei", "ying" }));
    set_race("human");
    set_level(50);
    
    set("long", "�y�v�����D�A�@�Ѧܰ��L�W����z�L�Τ����G��өФ��C\n"
                 );

    set("title", "���D");

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
    // �򥻧ޯ�
    set_skill("dodge", 150);
    set_skill("parry", 180);
    set_skill("combat", 150);
    set_skill("heavy hit", 160);
    set_skill("savage hit", 160);
    set_skill("continual hit", 160);
}

