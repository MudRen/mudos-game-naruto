#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIW"哈比兔"NOR, ({ "happy rabbit","rabbit"  }) );
    set_race("beast");
    set_level(10);

    set("long", "哈比兔族是一群狡猾的兔子，手鬼鬼崇崇的放在背後，不曉得再做什麼壞事？\n");

    set("limbs", ({ "兔耳", "眼睛", "身體", "屁股", "尾巴" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
 
    setup();

    if( random(100) > 0 ) carry_object("/world/area/wuyin/wp/chopping-knife.c")->wield("righthand");
    if( random(100) > 0 ) carry_object("/world/area/wuyin/eq/false-teeth.c")->wear();
    if( random(100) > 85 ) carry_object("/world/area/wuyin/eq/steel-teeth.c");

}
