#include <ansi.h>
inherit NPC;
void create()
{
    set_name("閻魔旱魃", ({ "yan mo han ba" , "ba" }) );
    set_race("human");
    set_level(80);
    set("long", "統領第一殿的魔族君主，生于沙場、死也沙場的一方霸主，魔君個性驍勇剽悍，\n"
                "狂傲中帶有冷靜，武功霸道高絕，臨敵時擅以強將攻心、\n"
                "單挑破局之戰術，親率魔界先鋒眾將，以絕對的強勢壓境征伐。\n");
    set("age",999);
    set("title", "異度魔君");
    setup();
    //carry_object(__DIR__"eq/blade.c")->wield();
}
