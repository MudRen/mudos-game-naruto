#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("金甲護衛", ({ "gold guild", "guild" }));
    set_race("human");
    set_level(35);
    
    set("long", "金甲護衛軍，魅城中精英。穿有高防護的金甲，\n"
                 );

    set("age", 500);
    set("gender", "male");

    setup();

    }  
