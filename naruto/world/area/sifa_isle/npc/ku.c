#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    string area_file = "/world/area/sifa_isle/aineaisi.c";
    object enemy, area;
    object* targets;
    int i, damage, raiseDamage, exact, evade;

    // 沒有敵人
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    i = random(3) + 1;

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // 牛牛果實-長頸鹿型態，已經用過才用技能
    if( !query("fruit_horse", 1) ) {
        message_vision(CYN"\n$N使用動物系『"HIY"牛牛果實"NOR"─"BLINK+YEL"長頸鹿型態"NOR+CYN"』的效果，變化為長頸鹿了！\n"NOR, this_object());

        set_skill("sock power", 50);           // 新技能，專門用來提高致命機率，mob專用
        set_skill("sock bom", 25);             // 新技能，專門用來提高致命傷害，mob專用
        set_skill("paper step", 200);          // 增加紙繪發動率
        add_temp("apply/intimidate", 150);     // 攻擊能力
        add_temp("apply/wittiness", 200);      // 防禦能力
        add_temp("apply/evade", 100);          // 迴避
        add_temp("apply/exact", 150);          // 命中
        set("name", "卡庫"YEL"[長頸鹿]"NOR);   // 名字修正

        message_vision("$N說道："HIG"我就是喜歡長頸鹿！$n"HIG"有意見嗎！\n"NOR, this_object(), enemy);
        set("fruit_horse", 1);
        return;
    }
    // 有分多人攻擊或單人攻擊
    if( sizeof(targets) >= 2 ) {
        switch( i ) {
            case 1: // 嵐腳•飛鏢
                if( query("fruit_horse", 1) ) {
                    exact = COMBAT_D->evade(this_object(), enemy, 1)*1.1;

                    add_temp("apply/exact", exact);
                    message_vision("\n$N說道﹕"HIG"製麵機∼∼\n"NOR, this_object());
                    message_vision("$N"HIC"將脖子縮起伸長手腳使出"HIB"「嵐腳•飛鏢」"HIC"朝著四面八方射出飛鏢型的斬擊！\n"NOR, this_object(), enemy);
                    for(i=0;i<sizeof(targets);i++) {
                        if( !COMBAT_D->isHit(this_object(), targets[i]) ) {
                            message_vision(HIW"$N"HIW"改採防禦姿態，將飛來的斬擊全數擊落，沒有受傷。\n"NOR, targets[i]);
                        } else {
                            raiseDamage = 800;
                            add_temp("apply/attack", raiseDamage); 
                            damage = COMBAT_D->isDamage(this_object(), targets[i], 0);
                            add_temp("apply/attack", -raiseDamage);
                            targets[i]->receive_damage(damage, this_object());
                            message_vision( sprintf(HIR"銳利的飛鏢斬擊瞬間劃過$n"HIR"的身子，使$n"HIR"流血不止(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
                        }
                    }
                    add_temp("apply/exact", -exact);
                    message_vision("\n"NOR, this_object());
                    break;
                }
            case 2: // 麒麟陣雨
                if( query("fruit_horse", 1) ) {
                    exact = COMBAT_D->evade(this_object(), enemy, 1)*1.4;

                    message_vision("\n$N說道﹕"HIG"雖為四角，但無死角。\n"NOR, this_object());
                    message_vision("$N"HIK"將"NOR+YEL"長頸鹿"HIK"的身體縮成四方形，並且朝空中射出大量斬擊"HIW"「嵐腳」"HIR"\n當$n"HIR"還搞不清楚"NOR"$N"HIR"的企圖時，斬擊撞擊牆壁反彈射向$n"HIR"眾人，有如下雨般的"HIB+BLINK"『麒麟陣雨』"NOR+HIR"！\n\n"NOR, this_object(), enemy);
                    for(i=0;i<sizeof(targets);i++) {
                        if( targets[i]->is_busy() ) continue;
                        evade = COMBAT_D->evade(targets[i], this_object(), 1);

                        if( !COMBAT_D->SkillHit(this_object(), targets[i], exact, evade) ) {
                            message_vision(HIW"$N"HIW"只好先暫時放棄攻擊，躲離陣雨的攻擊範圍。\n"NOR, targets[i]);
                        } else {
                            raiseDamage = 500;
                            add_temp("apply/attack", raiseDamage); 
                            damage = COMBAT_D->isDamage(this_object(), targets[i], 0);
                            add_temp("apply/attack", -raiseDamage);
                            targets[i]->receive_damage(damage, this_object());
                            targets[i]->start_busy(2);
                            message_vision( sprintf(HIB"雨般的斬擊不斷從天而降劃傷$n"HIB"，根本無可防禦(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
                        }
                    }
                    message_vision("\n"NOR, this_object());
                    break;
                }
            case 3: // 嵐腳•亂
                command("say 光靠人多是打不贏老朽的！" );
                command("perform kick luan.kick on " + enemy->query_id() );
                break;
        }
        return;
    }
    switch( i ) {
        case 1: // 麒麟萬射櫓
            if( query("fruit_horse", 1) ) {
                exact = COMBAT_D->exact(this_object(), enemy, 1)*1.2;
                evade = COMBAT_D->evade(enemy, this_object(), 1);

                message_vision("\n$N"HIY"縮起頭部，將目標對準了$n"HIY"！"NOR+YEL+BLINK"『麒麟砲台』"NOR+HIY"蓄勢待發準備攻擊！\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision(HIK"$N"HIK"暗道不妙，瞬間壓低身子避開"HIW"「麒麟萬射櫓」"HIK"在牆上轟出一個方型大洞！\n\n"NOR, enemy);
                    start_busy(2);
                } else {
                    raiseDamage = 3000;
                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);
                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf(HIR"當$n"HIR"準備閃躲時，"NOR"$N"HIR"發動"HIW"「麒麟萬射櫓」"HIR"猛力擊中$n"HIR"！$n"HIR"悶哼一聲被擊飛出去！(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                    start_busy(1);
                    if( !objectp(area = load_object(area_file)) ) return;
                    if( !area->is_area() ) return;
                    if( !area_move(area, enemy, random(28)+1, random(28)+11) ) return;
                    message_vision(CYN"牆壁「轟隆」一聲巨響，身受重傷的$N"CYN"從裡面摔了出來。\n\n"NOR, enemy);
                }
                return;
                break;
            }
        case 2: // 嵐腳•龍斷
            exact = COMBAT_D->exact(this_object(), enemy, 1)*1.5;
            evade = COMBAT_D->evade(enemy, this_object(), 1);

            if( !enemy->is_busy() ) {
                raiseDamage = 1500;
                command("say 要不要用鐵塊來抵擋，是由我的眼睛來決定。" );
                message_vision("$N"HIK"一眼就看穿了"NOR"$n"HIK"接下來的行動，一招"NOR+YEL"『嵐腳•龍斷』"HIK"直接打擊"NOR"$n"HIK"要害！\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision("\t$n發現$N居然不使用鐵塊直接反擊，馬上變招擋下了攻擊。\n"NOR, this_object(), enemy);
                    start_busy(3);
                    enemy->start_busy(1);
                } else {
                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);
                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf(HIY"龍型斬擊咬中了$n"HIY"的要害，$n"HIY"慘叫一聲，一時間無法行動(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                    start_busy(1);
                    enemy->start_busy(5);
                }
                return;
                break;
            }
        case 3: // 嵐腳•白雷
            if( query_condition("white_cd") ) return;
            command("say 嵐腳！...白雷！" );
            command("perform kick thunder.kick on " + enemy->query_id() );
            break;
    }
    return;
}
void check_fruit()
{
    // 沒在戰鬥要回復成人型
    if( query("fruit_horse", 1) ) {
        set("name", "卡庫");                    // 名字修正
        message_vision("$N搖搖頭恢復成人型說道："HIG"其實老朽比較喜歡吃肉。\n"NOR, this_object());
        delete("fruit_horse");
        delete_skill("sock power");
        delete_skill("sock bom");
        set_skill("paper step", 160);           // 減少紙繪發動率
        add_temp("apply/intimidate", -150);     // 攻擊能力
        add_temp("apply/wittiness", -200);      // 防禦能力
        add_temp("apply/evade", -100);          // 迴避
        add_temp("apply/exact", -150);          // 命中
    }
    do_heal();
    return;
}
void create()
{
    set_name("卡庫", ({ "ka ku", "ka", "ku" }) );
    set_race("human");
    set_level(70);
    set_class("guard_sea");         // 海軍校衛
    set("classify", "strengthen");  // 強化
    set("age", 25);
    set("title", HIR"ＣＰ９"NOR);
    set("long", "鼻子長的方方正正的男人，身穿一件看起來很老成的運動服，其實年\n"
                "齡應該不會太大。只見他坐在房中似乎在等待著什麼事情的到來。閉\n"
                "著眼睛好像在思考什麼。\n"
                "海賊和海軍技能可互相學習，利用 train 指令來向卡庫學習技能。\n"
                "使用 list 指令查詢可學習的技能列表。\n" );

    set("chat_chance", 20);
    set("chat_msg", ({
        (: check_fruit :),
    }) );
    set("chat_chance_combat", 35);
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
    set_train_with_camp("combat", 1, 1, 200, "police", -2);             // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 180, "police", -2);              // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 180, "police", -2);              // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 140, "police", -2);          // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 160, "police", -2);         // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 200, "police", -2);      // 連擊之術
    set_train_with_camp("spurn", 1, 10, 200, "police", -2);             // 踢技基礎
    set_train_with_camp("kick haze", 1, 15, 180, "police", 1);          // 踢技：嵐腳
    set_train_with_camp("kick thunder", 0, 40, 80, "police", 2);       // 踢技：嵐腳•白雷
    set_train_with_camp("kick luan", 0, 30, 120, "police", 1);          // 踢技：嵐腳•亂

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(31), "p1":100, "p2":100 ]),   // 黃金
        ([ "type":"eq", "id":8, "amount":1, "p1":80, "p2":100 ]),                  // 灰色勁裝
    }) );
    setup();
    set_skill("combat", 200);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("heavy hit", 150);
    set_skill("savage hit", 160);
    set_skill("continual hit", 200);
    set_skill("spurn", 200);
    set_skill("body iron", 180);
    set_skill("paper step", 160);
    set_skill("kick haze", 200);
    set_skill("kick thunder", 200);
    set_skill("kick luan", 200);

    add_temp("apply/exact", 150);       // 命中
    add_temp("apply/evade", 100);       // 迴避
    add_temp("apply/intimidate", 150);  // 攻擊能力
    add_temp("apply/wittiness", 100);   // 防禦能力
    add_temp("apply/str", 15);
    add_temp("apply/dex", 25);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 85 + random(16);

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
    msg = "\n\n"+this_object()->query("name")+HIY"躺在地上說著：我輸了！以後該何去何從呢...\n\n"+enemy->query("name")+"隨口回道：你還有動物園阿...\n\n"NOR+this_object()->query("name")+HIY"隨即大笑著說：哈哈哈..."+enemy->query("name")+"這個人還真有趣阿...\n\n"NOR;
    msg += HIB"【世界政府】ＣＰ９「六式」高手"+this_object()->query("name")+HIB"("+this_object()->query("id")+")居然被"+enemy->query("name")+"("+enemy->query("id")+")擊敗了！\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死卡庫獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}
