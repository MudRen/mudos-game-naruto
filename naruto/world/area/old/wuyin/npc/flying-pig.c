#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("飛天豬", ({ "flying pig","pig" }) );
    set_race("beast");
    set_level(20);

    set("long", "一隻和黑豬王一樣的飛天白豬，常笑黑豬王是胖子但簡直是五十步笑一百步。\n");

    set("limbs", ({ "頭部", "腦門兒", "腹皮", "屁股" }) );
    set("verbs", ({ "bite" }) );
    
    set("attitude", "aggressive");         // 主動攻擊

    setup();


}
