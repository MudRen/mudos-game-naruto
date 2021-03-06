#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    mapping cnd = ([]), weapons;
    object enemy, ob;
    object* targets;
    string skill;
    int i;

    // 沒有敵人
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision(CYN"\n$N擺出撩人的姿態，用雙手磨擦身體，"HIW"白色泡沫"NOR+CYN"覆滿全身，看起來非常誘人。\n\n"NOR, this_object());

    cnd["name"] = HIW"(泡沫)"NOR;
    cnd["duration"] = 1;

    // 當攻擊人數超過兩人改用群體技
    // 效果還蠻驚人的，所以對多人命中低
    // 對單人則是一定中
    if( sizeof(targets) >= 2 ) {
        message_vision(NOR"泡泡愈來愈多，將$N整個人包覆在其中形成"HIW"『肥皂羊』"NOR"\n$N使用"HIM"『泡泡果實』"NOR"能力控制泡沫使出"HIC"「羊雲大海嘯」"NOR"泡沫衝向$n眾人！\n\n"NOR, this_object(), enemy);
        for(i=0;i<sizeof(targets);i++) {
            if( targets[i]->query_condition("golden_bubble", 1) ) continue;
            if( !COMBAT_D->isHit(this_object(), targets[i]) ) {
                message_vision(HIC"但是$N"HIC"立刻突破了海嘯，沒有被泡沫所吞噬。\n"NOR, targets[i]);
            } else {
                message_vision(HIW"$N"HIW"被海嘯吞沒，全身變的異常光滑！連站都站不穩了！\n"NOR, targets[i]);
                if( mapp(weapons = targets[i]->query_temp("weapon")) && sizeof(weapons) ) {
                    foreach(skill, ob in weapons) ob->unequip();
                }
                targets[i]->set("no_defend", 1);      // 不能防禦
                targets[i]->set("no_combat", 1);      // 不能攻擊
                targets[i]->set_condition("golden_bubble", cnd);
                tell_object(targets[i], HIY"(你全身太過光滑居然連站都站不穩跌在地上，武器也無法使用了)\n"NOR);
            }
        }
        message_vision("\n\n"NOR, this_object());
    } else {
        // 已經中了就不用再放了
        if( enemy->query_condition("golden_bubble", 1) ) return;

        message_vision(HIB"$N踢出"HIC"嵐腳"HIB"干擾$n"HIB"行動，隨即用"HIC"「剃」"HIB"移至$n"HIB"身後！\n"HIY"『黃金泡沫』"HIW"$N伸出雙手不停磨擦$n"HIW"的身體，$n"HIW"全身似乎愈來愈光滑！\n"NOR, this_object(), enemy);
        if( mapp(weapons = enemy->query_temp("weapon")) && sizeof(weapons) ) {
            foreach(skill, ob in weapons) ob->unequip();
        }
        enemy->set("no_defend", 1);      // 不能防禦
        enemy->set("no_combat", 1);      // 不能攻擊
        enemy->set_condition("golden_bubble", cnd);
        tell_object(enemy, HIY"(你全身太過光滑居然連站都站不穩跌在地上，武器也無法使用了)\n\n"NOR);
    }
    return;
}
void create()
{
    set_name("卡莉法", ({ "ka li fa", "fa", "_KALIFA_" }) );
    set_race("human");
    set_level(55);
    set("gender", "female");
    set_class("guard_sea");         // 海軍校衛
    set("classify", "strengthen");  // 強化
    set("age", 24);
    set("title", HIR"ＣＰ９"NOR);
    set("long", "長的很妖豔的女子，正悠閒的坐在椅子上喝著紅茶，她似乎對於紅茶\n"
                "的泡法斤斤計較，應該是一個對於任何事情都追求完美的女性吧。\n"
                "海賊和海軍技能可互相學習，利用 train 指令來向卡莉法學習技能。\n"
                "使用 list 指令查詢可學習的技能列表。\n" );

    set("chat_chance", 20);
    set("chat_msg", ({
        (: do_heal :),
    }) );
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // 選則海軍還是海賊並沒有影響
    set("guild", "piece");

    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 140, "police", -2);           // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 160, "police", -2);            // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 140, "police", -2);            // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 120, "police", -2);        // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 120, "police", -2);       // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 180, "police", -2);    // 連擊之術
    set_train_with_camp("martial", 1, 10, 140, "police", -1);         // 武術基礎
    set_train_with_camp("activity", 1, 10, 160, "police", -1);        // 特殊基礎
    set_train_with_camp("gun finger", 1, 15, 120, "police", -1);      // 武術：指槍
    set_train_with_camp("gun whip", 1, 15, 160, "police", -1);        // 武術：指槍•鞭
    set_train_with_camp("briar suffuse", 0, 40, 80, "police", 2);    // 特殊：荊棘之路

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(16), "p1":100, "p2":100 ]),   // 黃金
        ([ "type":"eq", "id":45, "amount":1, "p1":90, "p2":100 ]),                 // 尖刺護腕
        ([ "type":"eq", "id":5, "amount":1, "p1":95, "p2":100 ]),                  // 繩子
    }) );
    setup();
    set_skill("combat", 150);
    set_skill("dodge", 160);
    set_skill("parry", 140);
    set_skill("heavy hit", 130);
    set_skill("savage hit", 120);
    set_skill("continual hit", 200);
    set_skill("martial", 200);
    set_skill("gun finger", 200);
    set_skill("briar suffuse", 200);
    set_skill("gun whip", 200);
    set_skill("body iron", 120);
    set_skill("paper step", 160);

    add_temp("apply/evade", 120);        // 迴避
    add_temp("apply/intimidate", 50);    // 攻擊能力
    add_temp("apply/wittiness", 80);     // 防禦能力
    add_temp("apply/int", 20);
    add_temp("apply/dex", 10);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;
    message_vision("$N說道﹕"HIG"這是性搔擾。\n"NOR, this_object());
    return 1;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 15 + random(11);

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
    msg = "\n\n"HIC+this_object()->query("name")+"一臉驚訝地說：我是泡泡果實能力者！怎麼會輸！這是性騷擾！\n\n"NOR;
    msg += HIB"【世界政府】ＣＰ９「六式」高手"+this_object()->query("name")+"("+this_object()->query("id")+")居然被"+enemy->query("name")+"("+enemy->query("id")+")殺死了！\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死卡莉法獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}
