#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    object enemy;
    int i;

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( random(3) ) {
        case 0: // 獸嚴•梟亂打
            add_temp("apply/attack", 300);
            message_vision(HIC"\n$N"HIC"將兩臂伸直，以指槍的速度連續使出"HIR"『"HIY"獸嚴"NOR"•"HIK"$N亂打"HIR"』"HIC"攻擊$n"HIC"！\n\n"NOR, this_object(), enemy);
            for(i=0;i<4;i++) {
                COMBAT_D->fight(this_object(), enemy, this_object());
            }
            message_vision(HIC"\n$N結束了亂擊！\n\n"NOR, this_object(), enemy);
            add_temp("apply/attack", -300);
            start_busy(4);
            break;
        default: // 鐵塊球
            command("perform body ball.atwirl on " + enemy->query_id() );
            break;
    }
}
void do_say()
{
    // 太吵了 讓機率再低一點
    if( random(100) < 1 ) {
        do_chat( ({ 
            (: command, "say 我絕對不會告訴你，這兩個機關能做什麼的！喳叭叭！" :),
            (: command, "say 其實是打開通往徬徨之橋路！喳叭叭！" :),
            (: command, "say ........" :),
            (: command, "say 又說溜嘴了！喳叭叭！" :),
            (: command, "say 反正打不贏我！別想動機關！喳叭叭！" :),
        }) );
    }
    do_heal();
}
void create()
{
    set_name("梟", ({ "xiao", "_XIAO_" }) );
    set_race("human");
    set_level(60);
    set_class("guard_sea");         // 海軍校衛
    set("classify", "strengthen");  // 強化
    set("age", 18);
    set("title", HIR"ＣＰ９"NOR);
    set("long", "長的圓滾滾，嘴巴上還有拉鍊的生物，他滔滔不絕地說著他是海軍特\n"
                "殊諜報集團ＣＰ９的成員，名字叫作梟，因為善於使用六式中的剃，\n"
                "能像貓頭鷹一般在暗處偷襲敵人。\n"
                "海賊和海軍技能可互相學習，利用 train 指令來向梟學習技能。\n"
                "使用 list 指令查詢可學習的技能列表。\n" );

    // 一般時動作
    set("chat_chance", 20);
    set("chat_msg", ({
        (: do_say :),
    }) );
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // 至於選則海軍還是海賊並沒有影響
    set("guild", "piece");

    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 120, "police", -2);            // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 200, "police", -2);             // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 100, "police", -2);             // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 140, "police", -2);         // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 130, "police", -2);        // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 150, "police", -2);     // 連擊之術
    set_train_with_camp("martial", 1, 10, 160, "police", -1);          // 武術基礎
    set_train_with_camp("animal yan", 0, 25, 120, "police", 1);        // 武術：獸嚴
    set_train_with_camp("paper step", 1, 15, 200, "police", 0);        // 特殊：紙繪
    set_train_with_camp("paper slime", 0, 20, 140, "police", 0);       // 特殊：紙繪•軟泥
    set_train_with_camp("body ball", 0, 40, 100, "police", 2);         // 特殊：鐵塊球

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(11), "p1":100, "p2":100 ]),   // 黃金
        ([ "type":"eq", "id":17, "amount":1, "p1":50, "p2":100 ]),                 // 風行靴
    }) );
    setup();
    set_skill("combat", 120);
    set_skill("dodge", 200);
    set_skill("parry", 100);
    set_skill("heavy hit", 140);
    set_skill("savage hit", 130);
    set_skill("continual hit", 150);
    set_skill("martial", 200);
    set_skill("animal yan", 200);
    set_skill("body ball", 200);
    set_skill("paper slime", 200);
    set_skill("gun finger", 180);
    set_skill("body iron", 180);
    set_skill("paper step", 200);

    add_temp("apply/exact", 100);       // 命中
    add_temp("apply/evade", 100);       // 迴避
    add_temp("apply/intimidate", 50);   // 攻擊能力
    add_temp("apply/wittiness", 50);    // 防禦能力
    add_temp("apply/dex", 30);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
int accept_kill(object me, string arg)
{
    if( !this_object()->query_condition("slime", 1) ) {
        message_vision("$N說道﹕"HIG"看我的紙繪•軟泥！喳叭叭！\n"NOR, this_object());
        command("perform paper slime.mud");
    } else {
        message_vision("$N說道﹕"HIG"喳叭叭！\n"NOR, this_object());
    }
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 20 + random(11);

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
    msg = "\n\n"GRN+this_object()->query("name")+"難過地叫著：喳叭叭！我無聲之梟居然會敗給"+enemy->query("name")+"∼∼\n\n"NOR;
    msg += HIB"【世界政府】ＣＰ９「六式」高手"+this_object()->query("name")+"("+this_object()->query("id")+")居然被"+enemy->query("name")+"("+enemy->query("id")+")殺死了！\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死梟獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}
