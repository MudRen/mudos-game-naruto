#include <npc.h>
#include <ansi.h>

inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    object enemy;

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( query_temp("snipe_ok") ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // 狙擊王模式開啟
    if( query("snipe_king", 1) ) {
        // 沒有使用狙擊之魂就先用
        if( !query_condition("snipe") ) {
            command("perform snipe soul.up");
        } else {
            message_vision("$N"CYN"撇開了以前的膽小，面對"NOR"$n"CYN"這般強敵依然冷靜思考對策...\n"NOR, this_object(), enemy);
            set_temp("snipe_ok", 1);
            call_out("snipe",2, this_object());
        }
    } else {
        if( query_stat_current("hp") < query_stat_maximum("hp")*1/3 ) {
            message_vision("\n$N痛苦地說道﹕"HIG"...我快死了..！救我！狙擊王！\n"NOR, this_object());
            message_vision(CYN"只見$N從懷中拿出一塊面具帶在臉上...\n\n"NOR, this_object());
            set_level(50);
            set_name(YEL"狙擊王"NOR, ({ "snipe king", "king" }) );
            set("title", HIW"百發百中"NOR);
            set("snipe_king", 1);

            set_stat_current("hp", query_stat_maximum("hp"));
            set_stat_current("ap", query_stat_maximum("ap"));
            set_stat_current("mp", query_stat_maximum("mp"));

            add_temp("apply/exact", 150);       // 命中
            add_temp("apply/evade", 200);       // 迴避
            add_temp("apply/intimidate", 171);  // 攻擊技巧
            add_temp("apply/wittiness", 130);   // 防禦技巧
            add_temp("apply/dex", 15);
            command("wear mask");
            return;
        } else if( this_object()->query_stat_current("hp") < this_object()->query_stat_maximum("hp")/2 ) {
            command("think");
            command("perform ketchup star.die");
        }
    }
    return;
}
void snipe(object ob)
{
    string msgin, msgout;
    object enemy;
    object* targets;
    int i;

    enemy = query_opponent();
    targets = ob->query_enemy();

    if( !is_fighting() ) {
        delete_temp("snipe_ok");
        return;
    }
    if( !enemy ) {
        delete_temp("snipe_ok");
        return;
    }
    if( environment(ob)->is_area() ) {
        if( !area_environment(ob, enemy) ) {
            delete_temp("snipe_ok");
            return;
        }
    } else {
        if( environment(enemy) != environment(ob) ) {
            delete_temp("snipe_ok");
            return;
        }
    }
    if( query_temp("snipe_check") > 4 ) {
        message_vision("\n$N"CYN"擦了擦頭上的汗水，累的喘不過氣。\n\n"NOR, this_object(), enemy);
        delete_temp("snipe_check");
        delete_temp("snipe_ok");
        return;
    }
    message_vision("\n$N說道："HIG"只要讓$n無法出手攻擊！我就有勝算！\n\n"NOR, this_object(), enemy);
    switch ( random(4) ) {
        case 0: 
            msgin = "$N"BYEL"拿出味貝一按開關，噗地一聲噴出大量黃色臭氣！哇！是屁！好臭！\n"NOR;
            msgout = "$n"HIY"受不了屁的味道，居然就此停住了攻擊！\n"NOR;
            break;
        case 1:
            msgin = "$N"HIK"在自己的身旁灑下大量的脊！\n"NOR;
            msgout = "讓$n無法靠近進行攻擊！\n"NOR;
            break;
        case 2:
            msgin = "$N"YEL"拿出閃光貝，忽然四周射出強烈刺眼的光芒！\n"NOR;
            msgout = "$n"HIY"的眼睛被光線照射到，居然張不開眼無法攻擊！\n"NOR;
            break;
        case 3:
            msgin = "$N"REV"從腰包拿出三顆彈丸朝旁邊一射，白色濃煙將附近都覆蓋了！\n"NOR;
            msgout = "$n"HIW"一時間看不到$N的位置！不能攻擊！\n"NOR;
            break;
    }
    message_vision(msgin, ob);
    for(i=0;i<sizeof(targets);i++) {
        targets[i]->start_busy(5);
        message_vision(msgout, ob, targets[i]);
    }
    call_out("snipe", random(2)+5, this_object(), enemy);
    add_temp("snipe_check", 1);
    return;
}
void to_do_say()
{
    if( query("snipe_king") ) {
        set_name("騙人布", ({ "usopp" }) );
        set("title", YEL"狙擊王"NOR);
        set_level(40);

        add_temp("apply/exact", -150);       // 命中
        add_temp("apply/evade", -200);       // 迴避
        add_temp("apply/intimidate", -171);  // 攻擊技巧
        add_temp("apply/wittiness", -130);   // 防禦技巧
        add_temp("apply/dex", -15);
        delete("snipe_king");
        message_vision("$N"CYN"偷偷摸摸地張望四周，眼看沒人，才將面具取下。\n"NOR, this_object());
        command("remove mask");
    }
    do_heal();
    return;
}
void create()
{
    set_name("騙人布", ({ "usopp" }) );
    set_race("human");
    set_level(40);
    set_class("thief_sea");         // 海賊
    set("classify", "strengthen");  // 強化
    set("age", 16);
    set("title", YEL"狙擊王"NOR);
    set("long", "出生在狙擊島的狙擊王阿∼百發百中啦啦啦∼∼鼻子長長的船員正\n"
                "唱著某主題曲？他就是草帽海賊團的前代理船工加狙擊手騙人布，\n"
                "目標是成為勇敢的海上戰士。\n"
                "海賊和海軍技能可互相學習，利用 train 指令來向騙人布學習技能\n"
                "使用 list 指令查詢可學習的技能列表。\n" );

    set("chat_chance", 50);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );

    // 接受過騙人布的教學便加入海賊王部份
    // 至於選則海軍還是海賊並沒有影響
    set("guild", "piece");

    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 140, "robber", -2);               // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 200, "robber", -2);                // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 100, "robber", -2);                // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 120, "robber", -2);            // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 120, "robber", -2);           // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 200, "robber", -2);        // 連擊之術
    set_train_with_camp("activity", 1, 10, 160, "robber", -2);            // 特殊基礎
    set_train_with_camp("interfere star", 1, 15, 140, "robber", -1);      // 特殊：干擾星
    set_train_with_camp("ketchup star", 0, 15, 120, "robber", 0);         // 特殊：蕃茄醬星
    set_train_with_camp("attack star", 1, 21, 160, "robber", -1);         // 特殊：攻擊星
    set_train_with_camp("snipe soul", 0, 25, 100, "robber", 1);           // 特殊：狙擊之魂
    set_train_with_camp("super star", 0, 40, 100, "robber", 2);           // 特殊：必殺

    set("set_drop", ({
        ([ "type":"wp", "id":65, "amount":1, "p1":1, "p2":450 ]),       // 兜弓
        ([ "type":"wp", "id":64, "amount":1, "p1":100, "p2":100 ]),     // 彈弓
        ([ "type":"eq", "id":116, "amount":1, "p1":1, "p2":800 ]),      // 狙擊王面具
    }) );

    setup();
    set_skill("combat", 150);
    set_skill("dodge", 200);
    set_skill("parry", 140);
    set_skill("heavy hit", 150);
    set_skill("savage hit", 150);
    set_skill("continual hit", 200);
    set_skill("activity", 200);
    set_skill("interfere star", 200);
    set_skill("ketchup star", 200);
    set_skill("attack star", 200);
    set_skill("super star", 200);
    set_skill("snipe soul", 200);

    add_temp("apply/exact", 50);        // 命中
    add_temp("apply/dex", 15);

    carry_object(__DIR__"wp/du_bow.c")->wield("twohanded");
    carry_object(__DIR__"eq/mask.c");
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 40 + random(11);

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
    msg = "\n\n"YEL"救我！狙擊王！....連狙擊王也無法救我了嗎...\n\n我要成為勇敢的海上戰士！...原來只是個可笑的謊言！\n\n"NOR;
    msg += HIR"【社會新聞】"NOR+YEL"「狙擊王」"HIR+this_object()->query("name")+"("+this_object()->query("id")+")慘敗於"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")之手！\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    set_name("騙人布", ({ "usopp" }) );  // 名字換回來吧
    tell_object(killer, HIY"(因為你殺死騙人布獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}

int accept_kill(object me, string arg)
{
    if( query("snipe_king", 1) ) {
        message_vision("$N說道﹕"HIG"我可是狙擊島的狙擊王！\n"NOR, this_object());
    } else {
        message_vision(CYN"$N慘叫一聲, 滿臉「那也安捏?!?!?」的表情.\n"NOR, this_object());
        message_vision("$N說道﹕"HIG"你..你你..你再不逃走可沒機會了喔！\n"NOR, this_object());
    }
}

int accept_fight(object me, string arg)
{
    do_chat( ({
        (: command, "say 什..什什麼決..決鬥！去找魯夫！" :),
        (: command, "fear" :),
    }) );
    return 0;
}
