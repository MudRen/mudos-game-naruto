#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�K�ҧL", ({ "iron guild", "iron", "guild" }));
    set_race("human");
    set_level(23);
    
    set("long", "�e�W�窺�h�L�A���F��ܥ~�ġA�٭n����d�Ǫ��ƶq�A�ҥH���j�駧�C\n"
                 );

    set("attitude", "aggressive");         // �D�ʧ���

     set("age", 200);
    set("gender", "male");

    setup();

    }  

