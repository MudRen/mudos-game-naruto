#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;    // 訓練忍者

int bird = 0;

void do_fight()
{
    object *targets;
    object enemy;
    int damage, raiseDamage, ntar, i, exact, evade;
    mapping cnd = ([]);

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
    switch ( random(6) ) {
        case 0:  // 火遁-豪火球之術
            if( query_condition("ghost_cd") ) break;
            add_temp("apply/exact", 200);
            message_vision("\n$N開始快速結印，接著將空氣吸入口中"HIW"『"NOR+RED"火遁"NOR"-"HIR"豪火球之術"HIW"』"NOR"吐出一團火球噴向$n！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->isHit(this_object(), enemy) ) {
                message_vision("火球轟隆一聲打擊在一旁的草地上，將整片草地燒成一片荒野。\n\n"NOR, this_object(), enemy);
            } else {
                raiseDamage = 900;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 300 ) damage = random(200) + 100;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("火球打擊在$n的身上後瞬間炸裂開來，不但炸傷了$n，還使$n身上燃燒了起來(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);

                if( !enemy->query_condition("firedamage") ) {
                    cnd["name"] = HIR+"著火狀態"+NOR;
                    cnd["duration"] = 15;
                    cnd["from"] = this_object();

                    enemy->set_condition("firedamage", cnd);
                }
                cnd["name"] = RED+"(CD)火遁"+NOR;
                cnd["duration"] = 3;

                this_object()->set_condition("ghost_cd", cnd);
            }
            add_temp("apply/exact", -200); 
            break;
        case 1:  // 水遁-大瀑布之術
            if( query_condition("tiger_cd") ) break;
            exact = COMBAT_D->intimidate(this_object(), 1)*1.2;

            message_vision("\n$N結了幾個印喊道"HIW"『"NOR+BLU"水遁"NOR"-"HIC"大瀑布之術"HIW"』"NOR"從$N的身後突然衝出一道巨浪，將天空籠罩一片漆黑！\n"NOR, this_object(), enemy);
            for(i=0;i<ntar;i++) {
                evade = COMBAT_D->wittiness(targets[i], 1);
                if( !COMBAT_D->SkillHit(this_object(), targets[i], exact, evade) ) {
                    if( userp(targets[i]) ) tell_object(targets[i], HIY"(防禦成功) "NOR);
                    raiseDamage = 0;
                } else {
                    if( userp(targets[i]) ) tell_object(targets[i], HIR"(防禦失敗) "NOR);
                    raiseDamage = 700;
                }
                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 100 ) damage = 80 + random(21);

                message_vision( sprintf("巨浪從空中俯衝而來，根本無從閃避，只能靠自己的防禦硬擋此招(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            }
            cnd["name"] = BLU+"(CD)水遁"+NOR;
            cnd["duration"] = 4;

            this_object()->set_condition("tiger_cd", cnd);
            message_vision("\n"NOR, this_object());
            break;
        case 2:  // 土遁-心中斬首術
            if( query_condition("age_cd") ) break;
            exact = COMBAT_D->intimidate(this_object(), 1);
            evade = COMBAT_D->wittiness(enemy, 1);

            message_vision("\n$N忽然間放慢結印速度結出"HIW"『"NOR+YEL"土遁"NOR"-"HIY"心中斬首術"HIW"』"NOR"之印，臉上露出深不可測的微笑...\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("但是$n並沒有對此做出任何行為，$N只好搖搖頭嘆了一口氣。\n\n"NOR, this_object(), enemy);
            } else {
                message_vision("$n以為有機可趁發動攻擊，卻中了替身術，被$N拉進土中只剩頭部外露動彈不得！\n\n"NOR, this_object(), enemy);
                enemy->start_busy(5);
            }
            cnd["name"] = YEL+"(CD)土遁"+NOR;
            cnd["duration"] = 8;

            this_object()->set_condition("age_cd", cnd);
            start_busy(2);
            break;
        case 3:  // 雷遁-千鳥
            if( query_condition("lion_cd") ) break;
            if( bird < 3 ) {
                message_vision(HIC"\b$N右手開始凝聚高密度的查克拉，不知道想做什麼...\n"NOR, this_object(), enemy);
                bird += 1;
                break;
            }
            add_temp("apply/exact", 300);
            message_vision(HIC"\b\n$N將凝聚在右手上的查克拉，發出有如千隻鳥鳴叫之雜音"HIK+BLINK"『"HIY"雷遁"NOR+BLINK"-"HIW"千鳥"HIK"』"NOR+HIC"攻擊$n"HIC"！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->isHit(this_object(), enemy) ) {
                message_vision("結果$n閃開了千鳥的攻擊！而攻擊擊中一旁樹幹放出強烈電流，連$n都感覺身子麻麻的。\n\n"NOR, this_object(), enemy);
                enemy->start_busy(1);
            } else {
                raiseDamage = 5500;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 1200 ) damage = random(800) + 400;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("強烈的雷擊瞬間刺穿$n的身體，$n只感覺眼前一白，連靈魂都快被電流毀滅了(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                enemy->start_busy(2);

                if( enemy->query_stat_current("hp") > 100 ) {
                    remove_killer(enemy);
                    enemy->remove_killer(this_object());
                    enemy->unconcious();
                }
            }
            add_temp("apply/exact", -300);
            cnd["name"] = HIY+"(CD)雷遁"+NOR;
            cnd["duration"] = 10;

            this_object()->set_condition("lion_cd", cnd);
            bird = 0;
            start_busy(2);
            break;
        case 4:  // 水遁-水鮫彈之術
            if( query_condition("tiger_cd") ) break;
            message_vision("\n$N連續結了幾個印施展出"HIW"『"NOR+BLU"水遁"NOR"-"HIB"水鮫彈之術"HIW"』"NOR"一顆巨大的水彈向游龍般躍向$n！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->isHit(this_object(), enemy) ) {
                message_vision("沒擊中$n的水鮫彈好像活在水中魚，在草地上濺起一陣水花後就消失了。\n\n"NOR, this_object(), enemy);
            } else {
                raiseDamage = 1600;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 600 ) damage = random(400) + 200;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("水鮫彈將$n擊飛了出去，但是衝擊力卻依然不減，一直將$n衝上十尺高空才逐漸崩壞(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            }
            cnd["name"] = BLU+"(CD)水遁"+NOR;
            cnd["duration"] = 6;

            this_object()->set_condition("tiger_cd", cnd);
            break;
        case 5:  // 千年殺
            add_temp("apply/exact", 400);
            command("say 木葉體術奧義！");
            command("perform thousand year kill.attack on " + enemy->query_id() );
            add_temp("apply/exact", -400);
            break;
    }
    return;
}

void to_do_say()
{
    if( bird != 0 ) {
        message_vision(HIY"$N懶洋洋地將手上聚集的查克拉收回。\n"NOR, this_object());
        bird = 0;
    }
    do_heal();
    return;
}

void create()
{
    set_name("旗木卡卡西", ({ "ka ka si", "si" }));
    set_race("human");
    set_level(70);
    set_class("superior");          // 上忍
    set("classify", "strengthen");  // 強化
    set("long", "卡卡西是木葉忍者村裡的上忍，是天才忍者木葉白牙「旗木朔茂」的兒子\n"
                "，一頭的銀髮和庸懶的眼神是他的特色。非宇智波一族的他卻擁有寫輪眼\n"
                "，因此獲得拷貝忍者的美名，但在其背後卻有一段不為人知的過去。\n"
                "六歲即為中忍的天才型忍者，左眼為寫輪眼，有暗部的經歷，能拷貝千種\n"
                "以上忍術，被稱為木葉第一技師。\n"
                "================================ 比司吉(mother) & 懷園(kaien) ==\n" );

    set("title", "拷貝忍者");
    set("age", 26);
    set("gender", "male");
    set("camp", "muye");
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    set("chat_chance", 10);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    // 設定忍者村，相同的忍者村才會教
    set("guild", "muye");
    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 180, "muye", -2);             // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 200, "muye", 0);               // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 200, "muye", 0);               // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 180, "muye", -1);          // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 180, "muye", -1);         // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 200, "muye", -1);      // 連擊之術
    set_train_with_camp("force", 1, 10, 180, "muye", -1);             // 體術
    set_train_with_camp("ninja", 1, 10, 200, "muye", 0);              // 忍術
    set_train_with_camp("alter ego", 0, 15, 160, "muye", -1);         // 忍術：分身術
    set_train_with_camp("thousand year kill", 0, 21, 140, "muye", 0); // 體術：千年殺

    setup();
    set_skill("ninja", 200);
    set_skill("force", 200);
    set_skill("thousand year kill", 200);
    set_skill("substitute", 200);
    map_skill("dodge", "substitute");

    add_temp("apply/armor", 100);       // 防禦能力
    add_temp("apply/intimidate", 100);  // 攻擊技巧
    add_temp("apply/wittiness", 150);   // 防禦技巧
    add_temp("apply/exact", 150);       // 命中能力
    add_temp("apply/evade", 150);       // 命中能力
    add_temp("apply/str", 15);
    add_temp("apply/dex", 15);
}

// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "千年殺" ) {
        if( me->query("guild") != "muye") {
            message_vision("$N說道﹕"HIG"千年殺是木葉體術奧義，$n這個村外人就別問那麼多了。\n"NOR, this_object(), me);
            return 1;
        }
        if( me->query_skill("thousand year kill") ) {
            message_vision("$N說道﹕"HIG"原來是是$n，如何？千年殺好用嗎？\n"NOR, this_object(), me);
            return 1;
        }
        if( !me->query_temp("learn_thousand") ) {
            message_vision("$N說道﹕"HIG"$n想學千年殺？那可沒那麼容易啊。\n"NOR, this_object(), me);
            message_vision("$N說道﹕"HIG"那本小說「"NOR+YEL"親熱天堂"HIG"」有幾個細節我有點記不清了...\n"NOR, this_object(), me);
            message_vision("$N說道﹕"HIG"去弄一本過來讓我看看吧。\n"NOR, this_object(), me);
            me->set_temp("learn_thousand", 1);
        } else {
            message_vision("$N對著$n說道﹕"HIG"我要的小說呢？$n不想學千年殺啦？\n"NOR, this_object(), me);
        }
    }
    return 1;
}

int accept_object(object me, object item)
{
    if( !objectp(me) || !objectp(item) ) return 0;
    if( !me->query_temp("learn_thousand") ) return 0;
    if( !item->id("_KISS_") ) return 0;

    message_vision("$N說道﹕"HIG"親熱天堂拿來了嗎？不錯不錯！\n"NOR, this_object(), me);
    message_vision("突然之間$n走到了$N身後，使出一招"HIW"「"HIR"千年殺"HIW"」"NOR"往$N的屁眼狠狠插入！！\n", me, this_object());
    me->set_skill("thousand year kill", 1);
    me->delete_temp("learn_thousand");
    do_chat( ({ 
        (: command, "say 千年殺的技巧記住了嗎？哇哈哈..." :),
        (: command, "gy si":),
        (: destruct, item :),
    }) );
    return 1;
}

void die()
{
    object enemy, killer;
    int i = 55 + random(16);
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
    msg = HIW"\n一則令人震驚的消息傳遍各大忍者村...\n\n"HIG"在世間小有名氣的"+enemy->rank()+enemy->query("name")+"，居然隻身前往木葉隱村挑戰"+this_object()->query("name")+"\n\n"HIR"在連番戰鬥之後，"+this_object()->query("name")+"因使用血輪眼過度疲勞有機可趁\n\n"HIW"被"+enemy->query("name")+"不斷猛攻之下終於承受不住傷害因此而敗陣下來！\n\n"NOR;
    msg += HIG"【"HIR"木葉快訊"HIG"】"HIG"有"HIW"『"HIR"拷貝忍者"HIW"』"HIG"之稱的"+this_object()->query("name")+"，居然被"+enemy->query("name")+"所擊敗，真是讓人不敢相信！\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死"+this_object()->query("name")+"獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}
