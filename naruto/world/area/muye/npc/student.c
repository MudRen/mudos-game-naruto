#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("學徒", ({ "student" }) );
    set_race("human");
    set_level(5);
    set("age", 13);
    set("long", "鐵器老闆收的小徒弟，只會做些簡單的器具。\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        CYN"學徒專心的聆聽鐵器老闆的指導。\n"NOR,
    }));
    setup();
}
