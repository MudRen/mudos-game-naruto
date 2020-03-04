#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIY"章頭鼠目"NOR, ({ "thin taco","taco" }) );
    set_race("beast");
    set_level(32);

    set("long", "骨瘦如柴的章魚，和肥腿章是一大對比，速度移動非常的快，章魚嘴裡還不時留出墨汁。\n");

    set("limbs", ({ "觸腳", "嘴巴", "頭部", "腹部" }) );
    set("verbs", ({ "bite" }) );
 
    setup();

    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/taco-burn.c");
    if( random(100) > 70 ) carry_object("/world/area/wuyin/eq/octopus-cap.c")->wear();
    if( random(100) > 70 ) carry_object("/world/area/wuyin/eq/eyepatch.c")->wear();
    if( random(100) > 95 ) carry_object("/world/area/wuyin/wp/pirate-blade.c");

}
