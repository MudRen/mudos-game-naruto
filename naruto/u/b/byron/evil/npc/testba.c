#include <ansi.h>
inherit NPC;
void create()
{
    set_name("閻魔旱魃", ({ "yan mo han ba" , "ba" }) );
    set_race("human");
    set_level(80);
    set_attr("str", 50);
    set_attr("con", 50);
    set_attr("dex", 50);
    set_attr("int", 50);
    set_stat_maximum("ap",1000);
    set_stat_maximum("hp",1000);
    set_stat_maximum("mp",1000);
    set("long","統領第一殿的魔族君主，生于沙場、死也沙場的一方霸主，魔君個性驍勇剽悍，\n"
                "狂傲中帶有冷靜，武功霸道高絕，臨敵時擅以強將攻心、\n"
                "單挑破局之戰術，親率魔界先鋒眾將，以絕對的強勢壓境征伐。\n");
    set("age",999);
    set("title", "異度魔君");
    setup();
    set_skill("combat",50);
    set_skill("parry",50);
    set_skill("dodge",50);
    set_skill("savage hit",50);
    set_skill("continual hit",50);
    set_skill("heavy hit",50);
    set_temp("apply/attack",0);         // 攻擊力量
    set_temp("apply/armor",0);         // 防禦力量
    set_temp("apply/intimidate",0);     // 攻擊能力
    set_temp("apply/wittiness",0);      // 防禦能力
    set_temp("apply/exact",0);          // 命中率
    set_temp("apply/evade",0);          // 迴避率
        
}

