#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�ȥ��@��", ({ "silver guild", "guild" }));
    set_race("human");
    set_level(30);
    
    set("long", "�ȥ��@�íx�A�y�������G�x�C\n"
                 );

    set("age", 300);
    set("gender", "male");

    setup();

    }  
