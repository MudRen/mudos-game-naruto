#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("���J", ({ "gan dan", "dan" }));
    set_race("human");
    set_level(70);
    
    set("long", "���J�@�ڤ��̱j�����J\n"
                 );

    set("title", "�������J");

    set("age", 26);
    set("gender", "male");

    setup();

    carry_object("/u/f/flying/wp/blevelsword")->wield();
    carry_object("/u/f/flying/eq/beq/bpants")->wear();
    carry_object("/u/f/flying/eq/beq/bwrist")->wear();
    carry_object("/u/f/flying/eq/beq/barmor")->wear();
    carry_object("/u/f/flying/eq/beq/bcloth")->wear(); 
    carry_object("/u/f/flying/eq/beq/bboots")->wear();
    carry_object("/u/f/flying/eq/beq/bgloves")->wear();

    // �򥻧ޯ�
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("combat", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 200);
}

