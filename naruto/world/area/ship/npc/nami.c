#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    object enemy;
    object* targets;
    int i, ntar;

    // 沒有敵人
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    ntar = sizeof(targets);

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( ntar > 0 ) enemy = targets[random(ntar)];
    else enemy = this_object()->query_opponent();

    if( !enemy->query_condition("rain") ) {
        command("perform drench.assoil on " + enemy->query_id() );
    } else if( !query_condition("thunderbolt") ) {
        command("perform thunderbolt lance.compo");
    } else if( ntar > 1 ) {
        command("perform powerful thunderbolt.jet on " + enemy->query_id());
    } else {
        command("perform thunderbolt lance.back on " + enemy->query_id());
    }
    return;
}
void create()
{
    set_name("娜美", ({ "nami", "_NAMI_" }) );
    set_race("human");
    set_level(40);
    set_class("thief_sea");         // 海賊
    set("classify", "strengthen");  // 強化
    set("age", 18);
    set("gender", "female");
    set("title", HIC"航海士"NOR);
    set("long", "包辦草帽海賊團的航行路境確認等事務，現在因為海賊船停駛中，\n"
                "娜美也閒著在畫著夢想中的海圖。因為某些原因對錢非常的執著，\n"
                "只要扯上錢就完全變個人了。\n"
                "海賊和海軍技能可互相學習，利用 train 指令來向娜美學習技能。\n"
                "使用 list 指令查詢可學習的技能列表。\n" );

    set("chat_chance", 30);
    set("chat_msg", ({
        (: do_heal :),
    }) );
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // 接受過娜美的教學便加入海賊王部份
    // 至於選則海軍還是海賊並沒有影響
    set("guild", "piece");

    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 120, "robber", -2);                  // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 160, "robber", -2);                   // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 160, "robber", -2);                   // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 170, "robber", -2);               // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 150, "robber", -2);              // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 180, "robber", -2);           // 連擊之術
    set_train_with_camp("activity", 1, 10, 160, "robber", -2);               // 特殊基礎
    set_train_with_camp("anemometer", 1, 15, 160, "robber", -1);             // 特殊：風速計
    set_train_with_camp("drench", 1, 21, 140, "robber", -1);                 // 特殊：滂沱大雨
    set_train_with_camp("chimera fay", 0, 20, 120, "robber", 0);             // 特殊：幻想妖精
    set_train_with_camp("powerful thunderbolt", 0, 30, 100, "robber", 2);    // 特殊：雷霆萬鈞
    set_train_with_camp("thunderbolt lance", 0, 40, 80, "robber", 2);       // 特殊：雷光槍

    set("set_drop", ({
        ([ "type":"wp", "id":67, "amount":1, "p1":1, "p2":500 ]),                 // 天候棒
        ([ "type":"wp", "id":62, "amount":1, "p1":80, "p2":100 ]),                // 表演用天候棒
        ([ "type":"obj", "id":28, "amount":30+random(120), "p1":100, "p2":100 ]), // 黃金
    }) );

    setup();
    set_skill("combat", 160);
    set_skill("dodge", 160);
    set_skill("parry", 200);
    set_skill("heavy hit", 200);
    set_skill("savage hit", 200);
    set_skill("continual hit", 160);
    set_skill("activity", 200);
    set_skill("anemometer", 200);
    set_skill("drench", 200);
    set_skill("chimera fay", 200);
    set_skill("powerful thunderbolt", 200);
    set_skill("thunderbolt lance", 200);

    add_temp("apply/evade", 250);       // 迴避
    add_temp("apply/int", 20);
    add_temp("apply/dex", 10);

    carry_object(__DIR__"wp/sky_stick.c")->wield("twohanded");
}

int accept_kill(object me, string arg)
{
    object ob;
    if( ob = present("_ROBIN_", environment(this_object())) ) {
        ob->dismiss_team();
        ob->set_team(0);
        message_vision("羅賓說道："HIG"航海士小姐是我們重要的伙伴。\n\n"NOR, ob);
        ob->set_team(this_object());
        ob->add_team_member(this_object());
        ob->kill_ob(me);
        if( function_exists("accept_kill", me) && !me->is_killing(ob) && me->accept_kill(ob) ) return 1;
        me->kill_ob(ob);
    }
    if( !query_condition("elf") ) {
        do_chat( ({(: command, "perform chimera fay.assoil" :)}) );
    }
}

int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "angry" :),
        (: command, "say 不要打擾我畫海圖。" :),
    }) );
    return 0;
}

void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 10 + random(6);

    if( !enemy ) {
        destruct(this_object());  // 找不到對手，直接消失
        return;
    }
    // 寵物殺死算主人的
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"HIC"一陣強風將桌上的海圖全部吹散，飛向偉大的航道各處...\n\n"HIW"但是海圖的主人再也無法預測風向天氣...也無法繼續畫海圖了...\n\n"NOR;
    msg += HIR"【社會新聞】"HIY"「小賊貓」"HIR+this_object()->query("name")+"("+this_object()->query("id")+")被惡名昭彰的壞蛋"+enemy->query("name")+"("+enemy->query("id")+")殺死了！\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死娜美獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}
