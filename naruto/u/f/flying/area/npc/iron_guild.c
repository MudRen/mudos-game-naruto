#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("鐵甲兵", ({ "iron guild", "iron", "guild" }));
    set_race("human");
    set_level(23);
    
    set("long", "前鋒營的士兵，除了抵抗外敵，還要壓制泥怪的數量，所以身強體壯。\n"
                 );

    set("attitude", "aggressive");         // 主動攻擊

     set("age", 200);
    set("gender", "male");

    setup();

    }  

