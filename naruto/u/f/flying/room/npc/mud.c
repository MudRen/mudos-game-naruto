#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("泥巴怪", ({ "mud monster", "monster" }));
    set_race("human");
    set_level(25);
    
    set("long", "惡沼中的泥巴怪物，數量很多，是魅城外圍的'防守主力。\n"
                 );
 
     set("age", 300);
    set("gender", "male");

    setup();

    }  
