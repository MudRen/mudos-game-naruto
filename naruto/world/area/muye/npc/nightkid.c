#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;
inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    string *point = ({ "百會", "神庭", "太陽", "耳門", "睛明", "人中",
                       "啞門", "風池", "人迎", "膻中", "鳩尾", "巨闕",
                       "神闕", "氣海", "關元", "中極", "曲骨", "鷹窗",
                       "乳中", "乳根", "期門", "章門", "商曲", "命門",
                       "肩井", "湧泉", "志室", "尾閭", "腎俞\", "太淵",
                       "肺俞\", "心俞\", "三陰交", "足三��", "氣海俞\", "厥陰俞\" });
    string msg = "";
    object enemy;
    int damage, raiseDamage, i, exact, evade, number=0;
    mapping cnd = ([]);

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( !query_condition("white_eyes") ) {
        command("perform white eyes.open");
    } else if( !query_condition("sky_palm_cd") ) {
        command("perform sky palm.attack");
    } else {
        switch( random(4) ) {
            case 0: // 百烈掌
                command("perform hundred palm.attack on " + enemy->query_id() );
                break;
            case 1: // 八卦六十四掌
                command("perform soft fist.attack on " + enemy->query_id() );
                break;
            case 2: // 八卦空掌
                message_vision("\n$N將查克拉凝聚在右手，隔空朝著$n打出一記"HIR"「"HIW"八卦空掌"HIR"」"NOR"無形勁道衝向$n！\n"NOR, this_object(), enemy);
                if( !COMBAT_D->isHit(this_object(), enemy) ) {
                    message_vision("「磅」地一聲，$n閃過了這無形的攻擊，勁道在樹上印出了一個掌印。\n\n"NOR, this_object(), enemy);
                } else {
                    raiseDamage = 1100;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 700 ) damage = 450 + random(251);

                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf("「碰」地一聲，$n感覺一道掌勁穿透自己的身體，登時喉嚨一陣甘甜，吐出了一口鮮血(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                }
                start_busy(3);
                break;
            case 3: // 柔拳點穴術
                if( query_condition("fang_cd") ) break;
                exact = COMBAT_D->exact(this_object(), enemy, 1) + COMBAT_D->intimidate(this_object(), 1);
                evade = COMBAT_D->evade(enemy, this_object(), 1);

                message_vision(HIR"\n$N擺出日向家標準攻擊姿態施展『"HIW"柔拳法•"HIC"點穴術"HIR"』攻向$n身上三十六個大穴！\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision("結果$n似乎猜中$N準備攻擊哪幾個穴位，隨即出手將攻擊隔開了。\n\n"NOR, this_object(), enemy);
                } else {
                    raiseDamage = 2000;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 500 ) damage = 350 + random(151);

                    if( enemy->query_stat_current("ap") > damage ) enemy->damage_stat("ap", damage, this_object());
                    else if( enemy->query_stat_current("ap") <= 0 ) enemy->set_stat_current("ap", 0);
                    else enemy->damage_stat("ap", enemy->query_stat_current("ap"), this_object());

                    for(i=0;i<4;i++) {
                        number += random(9);
                        if( i > 0 ) number += 1;
                        if( number > 36 ) number = random(36);
                        msg += point[number];
                        if( i < 3 ) msg += "、";
                    }
                    message_vision( sprintf("$n慘叫一聲，身上"+msg+"等要穴受到$N攻擊，頭痛欲裂，精神上受到極大的衝擊！(%d)\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                }
                cnd["name"] = HIW+"(CD)點穴"+NOR;
                cnd["duration"] = 5;

                this_object()->set_condition("fang_cd", cnd);
                break;
        }
    }
    return;
}

void to_do_say()
{
    if( query_condition("white_eyes") ) {
        message_vision(CYN"$N因為結束戰鬥而將白眼收回了。\n"NOR, this_object());
        delete_condition("white_eyes");
    }
    if( query_condition("sky_palm_cd") ) {
        message_vision(CYN"$N稍微閉上雙眼休息了一下，注意力似乎集中了。\n"NOR, this_object());
        delete_condition("sky_palm_cd");
    } else {
        switch( random(70) ) {
            case 10..15:
                do_chat( ({
                   (: command, "say 不管是分家還是宗家，都可以改變自己的人生。" :),
                   (: command, "say 是漩渦鳴人和父親讓我知道了這點。" :),
                   (: command, "say 很慶幸能在中忍試驗敗給漩渦鳴人。" :),
                }) );
                break;
            case 50..55:
                do_chat( ({
                   (: command, "say 保護木葉村與日向一族就是我的使命。" :),
                   (: command, "say 現在的我已經非常了解和任同這點了。" :),
                }) );
                break;
        }
    }
    do_heal();
    return;
}

void create()
{
    set_name("日向寧次", ({ "night kid", "kid" }));
    set_race("human");
    set_level(50);
    set_class("superior");          // 上忍
    set("classify", "strengthen");  // 強化
    set("camp", "muye");
    set("long", "木葉最強家族日向家的分家，擁有「白眼」的血繼限界。心中充滿了\n"
                "對宗家以及雛田的憎恨，想要將宗家徹底打垮，證明自己的能力不輸\n"
                "給宗家。但因鳴人的激勵，寧次面對雛田漸漸改變了看法。日向寧次\n"
                "臉上滿露出自信的樣子，頭額前有著父親所留下的咒印...。\n");

    set("nickname", HIG"分家"NOR);
    set("age", 16);
    set("gender", "male");

    // 一般時動作
    set("chat_chance", 10);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    // 戰鬥時動作
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("guild", "muye");
    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 180, "muye", -2);              // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 140, "muye", -2);               // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 160, "muye", -2);               // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 140, "muye", -2);           // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 100, "muye", -2);          // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 160, "muye", -2);       // 連擊之術
    set_train_with_camp("ninja", 1, 10, 140, "muye", -2);              // 忍術
    set_train_with_camp("force", 1, 10, 160, "muye", -2);              // 體術
    set_train_with_camp("hundred palm", 0, 15, 160, "muye", -1);       // 體術：百烈掌
    set_train_with_camp("white eyes", 0, 20, 120, "muye", 0);          // 忍術：白眼
    set_train_with_camp("soft fist", 1, 21, 140, "muye", -1);          // 體術：八卦六十四掌

    setup();
    set_skill("force", 200);
    set_skill("hundred palm", 200);
    set_skill("white eyes", 200);
    set_skill("soft fist", 200);
    set_skill("sky palm", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    add_temp("apply/exact", 150);        // 命中
    add_temp("apply/intimidate", 200);   // 攻擊技巧
    add_temp("apply/attack", 100);       // 攻擊能力
    add_temp("apply/str", 30);
}

void die()
{
    object enemy, killer;
    int i = 25 + random(6);
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        destruct(this_object());  // 找不到對手，直接消失
        return;
    }

    if( query_temp("dog_quit") ) { // 寵物的牙 直接死掉
        ::die();
        return;
    }

    // 寵物殺死算主人的
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = HIG"\n已經盡力了，卻還是不敵"+enemy->query("name")+"...\n\n"HIR"不過為了守護木葉村，這點事情是應該要做的吧...\n\n"HIW"就像父親當初為了守護日向宗家一樣...\n\n"NOR;
    msg += HIG"【"HIR"木葉快訊"HIG"】"HIG"木葉村兩大家族之一的日向"NOR"「分家」"HIG+this_object()->query("name")+"，經過一番奮戰之後敗給了"+enemy->query("name")+"...\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死"+this_object()->query("name")+"獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}

int accept_kill(object me, string arg)
{
    if( !query_condition("white_eyes") ) {
        message_vision("$N說道﹕"HIG"居然攻擊我！別來找死！\n"NOR, this_object());
        command("perform white eyes.open");
    } else {
        message_vision("$N說道﹕"HIG"這次不會放過$n了！\n"NOR, this_object(), me);
    }
}
