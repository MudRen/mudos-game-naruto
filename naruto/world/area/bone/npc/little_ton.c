#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("小通倍利", ({ "tonbeli" }));
    set_race("human");
    set_level(10);
    set("nickname",HIG"沒菜刀怪"NOR);
    set("age", 5);
    set("long","綠色提著燈籠的小妖怪，正因找不到菜刀而煩惱著。\n");
    setup();
}
