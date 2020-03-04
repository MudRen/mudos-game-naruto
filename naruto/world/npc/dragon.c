#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("神龍見皮不見頭", ({ "long skin of the dragon", "dragon" }));

    set_race("beast");
    set_level(39);

    set("age", 150);

    set("title", "好長");

    set("long", "頭皮很長的一條龍，頭都被蓋住了，走路跌跌撞撞的看不到路。\n");

    set("limbs", ({ "龍頭", "身體", "肚子", "龍腳", "尾巴", "龍背", "龍皮" }) );

    set("verbs", ({ "bite" }) );

    setup();
}
