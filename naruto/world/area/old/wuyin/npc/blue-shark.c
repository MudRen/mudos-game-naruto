#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(BLU"小藍鮫"NOR, ({ "blue shark","shark" }) );
    set_race("beast");
    set_level(29);

    set("long", "一隻小鯊魚，小小隻的看起來就很殺傷力，見到牠你還是趕快逃吧!。\n");

    set("limbs", ({ "魚背", "魚鰭", "魚頭", "魚齒", "魚尾" }) );
    set("verbs", ({ "bite" }) );
    
    set("attitude", "aggressive");         // 主動攻擊

    setup();

    carry_money("silver", 100);
    if( random(100) > 95 ) carry_object("/world/area/wuyin/eq/shark head")->wear();
}

