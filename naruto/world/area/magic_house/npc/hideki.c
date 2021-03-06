#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    object enemy;

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("SUMMON_DRAGON") == 0 ) {
        command("perform dragon-head draw.summon on " + enemy->query_id() );
    } else {
        command("perform psychical bullet.shoot on " + enemy->query_id() );
    }
    return;
}

// 不知為何松井秀喜招的念龍不能解除戰鬥中...
// 結果不會消失掉= =...只好另外寫刪除
void do_delete()
{
    object ob;
    if( this_object()->query_temp("SUMMON_DRAGON") != 0 && ob = present("_DRAGON_NPC_", environment(this_object())) ) {
        message_vision(ob->query("name")+HIY"發出一陣強光，消失在這裡了。\n"NOR, ob);
        destruct(ob);
    }
}

void create()
{
    set_name("松井秀喜", ({ "matsui hideki", "matsui", "hideki" }) );
    set_race("human");
    set_level(60);
    set_class("hxh_star");  // 一星獵人
    set("age", 26);
    set("camp", "hunter");
    set("nickname", HIM"酷斯拉"NOR);
    set("long", "魔術馬戲團召喚師，能夠驅使各種不同的召喚生物，其中有種類似\n"
                "古代龍的生物「酷斯拉」更是受到小朋友的喜愛，久而久之這也變\n"
                "成他的稱號了，表演項目為猛獸特技。可以利用train 指令來學習\n"
                "技能。使用 list 指令查詢可學習的技能列表。\n");

    set("chat_chance", 50);
    set("chat_msg", ({
        (: do_delete :),
    }) );

    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // 只教導獵人
    set("guild", "hunter");

    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 160, "hunter", -2);            // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 160, "hunter", -2);             // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 160, "hunter", -2);             // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 140, "hunter", -2);         // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 160, "hunter", 0);          // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 160, "hunter", -2);     // 連擊之術
    set_train_with_camp("emit", 1, 10, 200, "hunter", -1);             // 放出系程度
    set_train_with_camp("psychical bullet", 0, 15, 160, "hunter", -1); // 念彈
    set_train_with_camp("machine gun", 0, 21, 140, "hunter", 0);       // 雙手機關槍
    set_train_with_camp("dragon-head draw", 0, 20, 120, "hunter", 0);  // 龍頭戲畫

    setup();
    set_skill("combat", 160);
    set_skill("dodge", 160);
    set_skill("parry", 160);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 200);
    set_skill("continual hit", 160);
    set_skill("emit", 200);
    set_skill("psychical bullet", 200);
    set_skill("machine gun", 200);
    set_skill("dragon-head draw", 200);
}
int accept_fight(object me, string arg)
{
    return 0;
}
