#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�d�ک�", ({ "mud monster", "monster" }));
    set_race("human");
    set_level(25);
    
    set("long", "�c�h�����d�کǪ��A�ƶq�ܦh�A�O�y���~��'���u�D�O�C\n"
                 );

    set("attitude", "aggressive");         // �D�ʧ���

     set("age", 39985);
    set("gender", "male");

    setup();

    }  

