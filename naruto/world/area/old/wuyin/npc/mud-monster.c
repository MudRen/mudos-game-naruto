#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(YEL"�d�g��"NOR, ({ "mud monster","monster" }) );
    set_race("beast");
    set_level(25);

    set("long", "���W�G���G�L���d�h�ǡA���W���d�ߤ�������X�٤@�������b�a���C\n");

    set("limbs", ({ "�d��" }) );
    set("verbs", ({ "bite" }) );
    
    setup();

    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/mud.c");

}
