#include <npc.h>

void create()
{
        set_name("廟公", ({ "temple master", "master" }));
        set_race("human");
        set("age", 56);
        set("title", "土地公廟");
        set("long", "一位處理土地公廟大大小小事的廟公。\n");
        set("no_fight", 1);
        setup();
}
