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

    // �򥻧ޯ�
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("combat", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 200);
}


