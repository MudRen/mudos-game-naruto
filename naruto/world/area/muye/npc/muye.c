#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("木葉丸", ({ "muye" }));
    set_race("human");
    set_level(15);
    set("camp", "muye");
    set("long", "第三代火影的孫子，目標是擊敗爺爺成為火影。\n");

    set("age", 8);
    set("gender", "male");
    
    setup();

}
