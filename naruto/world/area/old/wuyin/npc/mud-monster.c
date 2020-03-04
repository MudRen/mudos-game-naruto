#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(YEL"泥土怪"NOR, ({ "mud monster","monster" }) );
    set_race("beast");
    set_level(25);

    set("long", "身上佈滿咒印的泥士怪，身上的泥漿不停的湧出還一直掉落在地面。\n");

    set("limbs", ({ "泥漿" }) );
    set("verbs", ({ "bite" }) );
    
    setup();

    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/mud.c");

}
