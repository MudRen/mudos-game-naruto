#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("果凍雞", ({ "jelly chicken","chicken"  }) );
    set_race("beast");
    set_level(1);

    set("long", "水之國特有的可愛的黃毛小雞，走在水之國的路上你一天可以遇到好幾個。\n");

    set("limbs", ({ "雞冠", "雞毛", "雞腿", "雞屁股", "雞胸" }) );
    set("verbs", ({ "bite" }) );
 
    set("chat_chance", 3);
    set("chat_msg", ({
        "果凍雞跳到你的身旁睜大眼看著你。\n",
        "果凍雞像小孩子似的蹦蹦跳跳.\n",
        "果凍雞開始嘟著小嘴裝可愛\n",
                (: random_move :),
        }));

    setup();
    // 削弱
    set_temp("apply/attack", -5);         // 攻擊力量
    set_temp("apply/defend", -5);         // 防禦力量
    set_temp("apply/exact", -5);          // 命中率
    set_temp("apply/evade", -5);          // 迴避率
    set_temp("apply/intimidate", -5);     // 攻擊能力
    set_temp("apply/wittiness", -5);      // 防禦能力

    carry_money("silver", 1);
    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/jelly.c");

}

