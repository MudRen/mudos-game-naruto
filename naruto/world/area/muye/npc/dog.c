#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("赤丸", ({ "dog", "_MY_PET_" }));
    set_race("beast");
    set_level(50);
    set("no_fight", 1);
    set("age", 8);
    set("long", "犬塚牙的狗，看起來小小隻的十分可愛。\n");
    setup();
}
