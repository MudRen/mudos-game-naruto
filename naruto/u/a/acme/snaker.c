#include <ansi.h>
#include <npc.h>

void create()
{
    set_name("蛇人", ({ "snaker" }));
    set_race("human");
    set("age", 20);
    set("title", RED"蛇人部族"NOR);
    set("long", "一隻蛇人。\n");
    set("camp", "snaker");
    setup();
}
