#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("���~", ({ "sen shou", "sen", "shou" }));
    set_race("human");
    set_level(20);
    
    set("long", "�˪L�����������~�A���|�D�ʧ����A���O����s�~���e�̤]���O�n�S���C\n"
                 );

    set("age", 70);
    set("gender", "male");

    setup();

    }  

