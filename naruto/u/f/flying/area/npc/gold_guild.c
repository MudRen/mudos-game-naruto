#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("�����@��", ({ "gold guild", "guild" }));
    set_race("human");
    set_level(35);
    
    set("long", "�����@�íx�A�y������^�C�靈�����@�����ҡA\n"
                 );

    set("age", 500);
    set("gender", "male");

    setup();

    }  
