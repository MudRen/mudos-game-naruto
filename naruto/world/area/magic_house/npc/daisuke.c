#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    object enemy, ob;
    int damage, damage_attack;

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( enemy->query_condition("hairstick", 1) == 0 ) {
        command("perform hair order.lunge on " + enemy->query_id() );
    } else if( ob = present("_VEGGIE_"+this_object()->query_id(), environment(this_object())) ) {
        if( !ob->is_fighting() ) {
            damage_attack = COMBAT_D->attack(this_object(), this_object(), 0, this_object()) - COMBAT_D->defend(enemy, enemy, 0);
            if( damage_attack < 0 ) damage_attack = 0;

            message_vision("$N向後一躍運用念力操縱"+ob->query("name")+"的行動，只見"+ob->query("name")+"立刻轉頭衝向$n！\n\n"NOR, this_object(), enemy);

            damage = ob->query_stat_maximum("hp")/2 + this_object()->query_skill("born-again branch") + random(100) + damage_attack;

            enemy->receive_damage(damage, this_object());
            message_vision( ob->query("name")+HIW"七手八腳的把"NOR"$n"HIW"纏住，身體的中心開始發出"HIR+BLINK"紅色光芒"NOR+HIW"！\n"NOR, this_object(), enemy);
            message_vision( sprintf("「三」「二」「一」轟隆巨響將$n炸的四分五裂(%d)%s\n\n", damage, COMBAT_D->report_status(enemy)), this_object(), enemy);

            this_object()->delete_temp("TREE_ONE");
            this_object()->delete_temp("TREE_TWO");
            destruct(ob);
        }
    }
    return;
}

void do_heal()
{
    object item;

    if( this_object()->query_condition("blood_cell_revive_cond") == 0 && this_object()->query_stat("hp") < this_object()->query_stat_maximum("hp")/2 ) {
        command("perform blood-cell revive.revive");
        return;
    } else {
        if( this_object()->query_temp("TREE_ONE") == 0 && this_object()->query_temp("TREE_TWO") == 0 ) {
            item = new(_DIR_AREA_"thorn_pine/npc/item/branch.c");
            item->move(this_object());
            command("perform born-again branch.crop");
        } else if( present("_TREE_", environment(this_object())) ) {
            item = new(_DIR_AREA_"thorn_pine/npc/item/water04.c");
            item->move(this_object());
            command("perform born-again branch.arise");
        }
    }
    return;
}

void create()
{
    set_name("松�竣j輔", ({ "matsuzaka daisuke", "daisuke" }) );
    set_race("human");
    set_level(60);
    set_class("hxh_star");  // 一星獵人
    set("age", 22);
    set("camp", "hunter");
    set("nickname", HIK"平成怪物"NOR);
    set("long", "原本居住在平成地區的小村中，因為能夠和樹木說話而被其他小孩\n"
                "當成怪物看待，直到魔術馬戲團發現他驚人的才能後，便將他帶進\n"
                "馬戲團，也不再被人岐視了。表演項目為操偶術。可以利用train \n"
                "指令來學習技能。使用 list 指令查詢可學習的技能列表。\n");

    set("chat_chance", 50);
    set("chat_msg", ({
        (: do_heal :),
    }) );

    set("chat_chance_combat", 100);
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
    set_train_with_camp("combat", 1, 1, 140, "hunter", -2);             // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 160, "hunter", -2);              // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 200, "hunter", 0);              // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 140, "hunter", -2);          // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 160, "hunter", -2);         // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 160, "hunter", -2);      // 連擊之術
    set_train_with_camp("operation", 1, 10, 200, "hunter", -1);         // 操作系程度
    set_train_with_camp("blood-cell revive", 0, 15, 160, "hunter", -1); // 血球再生
    set_train_with_camp("hair order", 1, 21, 140, "hunter", 0);         // 毛髮念控
    set_train_with_camp("born-again branch", 0, 20, 120, "hunter", 0);  // 樹枝重生

    setup();
    set_skill("combat", 140);
    set_skill("dodge", 160);
    set_skill("parry", 180);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 160);
    set_skill("continual hit", 160);
    set_skill("operation", 200);
    set_skill("blood-cell revive", 200);
    set_skill("hair order", 200);
    set_skill("born-again branch", 200);
}
int accept_fight(object me, string arg)
{
    return 0;
}
