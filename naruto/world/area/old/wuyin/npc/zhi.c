#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("魯汁", ({ "lu zhi", "zhi" }) );
        set_race("human");
        set_level(20);
        set("title","匠師");
        set("age", 70);
        set("long", "工匠的大師，傳言有句「魯汁門前弄大斧」顯示出魯汁的技術高超，\n"
                 "不是一般人可以比擬的，據傳魯汁是魯班的拜把兄弟...\n" );

        setup();
}
