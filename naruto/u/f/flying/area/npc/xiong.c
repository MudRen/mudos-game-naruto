#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("���~", ({ "xiong shou", "xiong", "shou" }));
    set_race("human");
    set_level(25);
    
    set("long", "�˪L�����������~�A�ݼɡA�y�ɴ��~���͡C\n"
                 );

    set("attitude", "aggressive");         // �D�ʧ���

    set("age", 70);
    set("gender", "male");

    setup();

    }  

