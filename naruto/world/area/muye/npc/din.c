#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;         // 訓練老師

void do_fight()
{
    object enemy;
    int i, j, damage, raiseDamage, exact, evade;

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( !query_condition("dp") ) {
        command("perform double physique.dp");
        return;
    }
    switch( random(2) ) {
        case 0:  // 肉彈戰車
            command("perform muscle tank.attack on " + enemy->query_id() );
            break;
        case 1:  // 針刺-肉彈戰車
            i = random(11) + 5;
            exact = COMBAT_D->intimidate(this_object(), 1) + query_attr("con")*3;
            evade = enemy->query_attr("con")*3;

            message_vision(CYN"\n$N從背後取下一條繩子，以極快的結法將"HIG+chinese_number(i)+NOR+CYN"把苦無綁在繩上"NOR"\n\n$N說道："HIG"讓$n嘗嘗秋道家秘技•肉彈戰車的強化版！\n\n"NOR, this_object(), enemy);
            message_vision(HIW"只見$N將繩子綁在身上，用他肥大的身軀施展起了"HIK"『針刺-"HIC"肉彈戰車"HIK"』"HIW"朝$n撞去！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("但是$n快速地從側邊閃了開來，留下一道深深的滾壓痕跡！\n\n\n"NOR, this_object(), enemy);
            } else {
                raiseDamage = 1150;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 500 ) damage = random(250) + 250;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf(HIR"「碰」地一聲，肉彈直接撞上了$n"HIR"，$n"HIR"只覺得喉嚨一甜，鮮血便吐了出來(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                message_vision(CYN"但是攻勢尚未停止，肉彈戰車持續旋轉著，繩上所綁的苦無不斷割傷$n"CYN"！\n"NOR, this_object(), enemy);
                for(i;i>0;i--) {
                    damage = i*20;
                    enemy->receive_damage(damage, this_object());
                    j = random(4) + 1;
                    damage += random(50);
                    message_vision(HIC""+chinese_number(i)+"把苦無劃傷了$n"HIC"，總共造成了 "HIR+damage+HIC" 點傷害！"NOR, this_object(), enemy);
                    if( i < j ) {
                        j = i;
                        i = 0;
                    } else {
                        i -= j - 1;
                    }
                    message_vision(HIK"("+chinese_number(j)+"把苦無因撞擊脫落)\n"NOR, this_object(), enemy);
                }
                message_vision(CYN"\n苦無全數脫落，$n立刻使勁彈離了$N！ "+COMBAT_D->report_status(enemy)+"\n\n"NOR, this_object(), enemy);
            }
            start_busy(5);
            return;
            break;
    }
    return;
}

void to_do_say()
{
    if( random(100) < 15 ) {
        do_chat( ({ 
            (: command, "say 肚子好餓啊∼我想吃一點不一樣的。" :),
            (: command, "say 有人能「幫忙」我找吃的嗎，餓的走不動∼" :),
        }) );
    }
    do_heal();
}

void create()
{
    set_name("秋道丁次" , ({ "din zhi", "zhi", "din" }) );
    set("guild", "muye");
    set_level(50);
    set("gender", "male");
    set_class("middle");            // 中忍
    set("classify", "strengthen");  // 強化
    set("age", 16);
    set("camp", "muye");
    set("long", "一個圓圓胖胖的木葉村忍者，看起來敢厚老實。屬於阿斯瑪小隊的成\n"
                "員。只見他手裡拿著零食不停的吃，吃完之後立刻以你肉眼無法辨識\n"
                "的速度又拿出一包新的零食繼續吃阿吃，讓人有種深不可測的感覺。\n");

    set("chat_chance", 20);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set_train_with_camp("combat", 1, 1, 140, "muye", -2);             // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 80, "muye", -2);               // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 160, "muye", -2);              // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 160, "muye", -2);          // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 180, "muye", -2);         // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 80, "muye", -2);       // 連擊之術
    set_train_with_camp("ninja", 1, 10, 120, "muye", -1);             // 忍術
    set_train_with_camp("force", 1, 10, 160, "muye", -1);             // 體術
    set_train_with_camp("double physique", 1, 15, 160, "muye", -1);   // 體術：倍化術
    set_train_with_camp("akimichi pill", 0, 20, 120, "muye", 0);      // 忍術：秋道秘藥
    set_train_with_camp("muscle tank", 0, 21, 140, "muye", 0);        // 體術：肉彈戰車

    setup();
    set_skill("combat", 150);
    set_skill("continual hit", 120);
    set_skill("heavy hit", 160);
    set_skill("savage hit", 200);
    set_skill("ninja", 140);
    set_skill("force", 200);
    set_skill("akimichi pill", 200);
    set_skill("double physique", 200);
    set_skill("muscle tank", 200);

    // 附加能力，等高能力有點差
    add_temp("apply/intimidate", 150);  // 攻擊技巧
    add_temp("apply/wittiness", 200);   // 防禦技巧
    add_temp("apply/armor", 300);       // 防禦能力
    add_temp("apply/con", 30);
}

void relay_say(object ob, string arg)
{
    if( !ob->query_skill("muscle tank") && arg == "幫忙" && ob->query("level") >= 20 )  {
        if( ob->query("guild") != "muye" ) {
            tell_object(ob, CYN"秋道丁次看了你一眼，發現你不是木葉忍者，便不好意思麻煩你了。\n");
            return;
        }
        if( !ob->query_temp("muscle_tank") ) {
            ob->set_temp("muscle_tank", 1);
            do_chat( ({ 
                (: command, "say 你想要幫忙我搜集食物嗎？" :),
                (: command, "say 太感謝了，我比較想吃「蟹黃生蠔鮑魚龜頭水果拉麵」，聽說一樂拉麵館老闆會煮。" :),
                (: command, "say 幫忙取得一份給我吧。" :),
            }) );
        } else {
            do_chat( ({ 
                (: command, "say 我不是已經拜託你了嗎？" :),
                (: command, "say 我比較想吃「蟹黃生蠔鮑魚龜頭水果拉麵」，聽說一樂拉麵館老闆會煮。" :),
                (: command, "say 幫忙取得一份給我吧。" :),
            }) );
        }
        return;
    }
}

int give_check(object ob)
{
    if( ob->id("_GOOD_FOOD_") ) return 1;              // 蟹黃生蠔鮑魚龜頭水果拉麵
    else return 0;
}

int accept_object(object me, object ob)
{
    object item;

    if( is_busy() ) {
        tell_object(me, "對方正在忙碌中，請等一下。\n");
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 別吵！沒看到我正在打架啊！" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( !me->query_temp("muscle_tank") ) {
                do_chat((: command, "say 我又沒要你幫我的忙，這怎麼好意思收下..." :));
                return 0;
            }
            message_vision("$N高興的又叫又跳...\n", this_object());

            if( !me->query_skill("muscle tank") ) {
                command("say 實在是太感謝了，我就教你肉彈戰車的技巧吧...\n");
                tell_object(me, HIW"(你學會了肉彈戰車了。)\n"NOR);
                me->set_skill("muscle tank", 1);
                me->delete_temp("muscle_tank");
            }
            do_chat( ({ ( : destruct , ob : ) }) );
            break;
    }
    return 1;
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
    // 寵物殺死算主人的
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n"+this_object()->query("name")+"哭喪著臉說道："HIG"我無法繼承秋道家的名號了！\n\n"HIY"父親...鹿丸...我辜負了你們的期待...\n\n"NOR;
    msg += HIG"【"HIR"木葉快訊"HIG"】"HIG"有"HIM"「豬、鹿、蝶」"HIG"之稱的秋道家忍者"+this_object()->query("name")+"，慘死於"+enemy->query("name")+"之手。\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死"+this_object()->query("name")+"獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}

int accept_kill(object me, string arg)
{
    if( query_condition("dp") == 0) {
        message_vision("$N說道﹕"HIG"想搶我的薯片嗎！！別想逃！\n"NOR, this_object());
        command("perform double physique.dp");
    } else {
        message_vision("$N說道﹕"HIG"薯片小偷！\n"NOR, this_object());
    }
}
