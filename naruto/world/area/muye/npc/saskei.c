#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("佐助", ({ "saskei" }));
    set_race("human");
    set_level(60);
    
    set("long", "擁有木葉村的「最優秀家族血統」的佐助，以第一名的成績畢業於忍\n"
                "者學校，是全村最為期待的頭號新血。\n");

    set("age", 16);
    set("gender", "male");
    
    setup();
}
