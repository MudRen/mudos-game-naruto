#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("刃霧", ({ "ren wu","wu" }) );
        set_race("human");
        set_level(20);
        set("title","霧中的狙擊手");
        set("age", 70);
        set("long", "一位身穿白色緊身衣的忍者，個性相當神秘低調。\n");

        setup();
}
