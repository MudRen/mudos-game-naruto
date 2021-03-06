#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
inherit F_TRAINER;    // 訓練導師

void do_fight()
{
    object enemy;
    int exact;

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // 當體力少於一定量，會用空氣門烙跑
    if( query_stat_current("hp") <= query_stat_maximum("hp")/3 ) {
        message_vision(CYN"\n$N發現自己敵不過$n的破壞力，立刻發動"NOR+GRN"『門門果實』"NOR+CYN"特殊能力"HIC"「空氣門」"NOR+CYN"絡跑了。\n\n"NOR, this_object(), enemy);
        if( !this_object()->move(_DIR_AREA_"sifa_isle/door.c") ) {
            message_vision(CYN"但是被$n看穿了，馬上發動攻擊阻止$N逃走。\n"NOR, this_object(), enemy);
            return;
        }
        this_object()->set("door_ok", 1);
        return;
    }
    // 先判斷有沒有用過鐵塊剛，沒用過就先使用
    // 迴旋門判斷如果對方還在 busy，一樣使用鐵塊碎
    if( this_object()->query_condition("gang_busy", 1) != 0) {
        switch( random(2) ) {
            case 0: // 技能1: 門門果實-迴旋門
                if( !enemy->is_busy() ) {
                    exact = COMBAT_D->exact(this_object(), enemy, 1)/5;

                    add_temp("apply/exact", exact);
                    message_vision(CYN"\n$N在空中使出"HIW"「月步」"NOR+CYN"以飛快的速度移至"NOR"$n"CYN"身後，伸手觸碰"NOR"$n"CYN"的臉部。\n"NOR, this_object(), enemy);
                    if( COMBAT_D->isHit(this_object(), enemy) ) {
                        message_vision(GRN"『門門果實-"NOR+REV"迴旋門"NOR+GRN"』"NOR"$n的眼睛忽然像旋轉門般不停轉動，頭昏眼花！\n\n"NOR, this_object(), enemy);
                        enemy->start_busy(5);
                    } else {
                        message_vision("但是$n一扭脖子就閃開了$N的觸摸。\n\n"NOR, this_object(), enemy);
                    }
                    add_temp("apply/exact", -exact);
                    break;
                }
            case 1: // 技能2: 鐵塊碎
                command("perform body sui.attack on " + enemy->query_id());
                break;
        }
        return;
    }
    command("perform body gang.defence");
    return;
}
void check_hp()
{
    // 回血完畢自動回到原屋子內
    if( query("door_ok", 1) ) {
        if( query_stat_current("hp") >= query_stat_maximum("hp") ) {
            if( !this_object()->move(_DIR_AREA_"sifa_isle/house1.c") ) return;
            message_vision(CYN"$N似乎將身體狀態回復完畢，從"HIC"「空氣門」"NOR+CYN"中走了出來。\n"NOR, this_object());
            delete("door_ok");
        }
    }
    // 順便將鐵塊剛的冷卻時間也消去
    if( query_condition("gang_busy") ) this_object()->delete_condition("gang_busy");

    // 預防他不回血...多設一個
    heal_stat("ap", query_stat_maximum("ap"));
    heal_stat("hp", query_stat_maximum("hp")/10);
    heal_stat("mp", query_stat_maximum("mp"));
    return;
}
void create()
{
    set_name("布魯諾", ({ "bruno" }) );
    set_race("human");
    set_level(60);
    set_class("guard_sea");         // 海軍校衛
    set("classify", "strengthen");  // 強化
    set("age", 31);
    set("title", HIR"ＣＰ９"NOR);
    set("long", "很高壯的男人，頭髮似乎有用什麼特別的髮膠，梳的像牛角一樣。他\n"
                "在屋子裡不時的調酒，整理櫃台，好像一個酒吧老闆。\n"
                "海賊和海軍技能可互相學習，利用 train 指令來向布魯諾學習技能。\n"
                "使用 list 指令查詢可學習的技能列表。\n" );

    set("chat_chance", 20);
    set("chat_msg", ({
        (: check_hp :),
    }) );
    set("chat_chance_combat", 50);
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
    set_train_with_camp("combat", 1, 1, 180, "police", -2);           // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 120, "police", -2);            // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 200, "police", -2);            // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 180, "police", -2);        // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 140, "police", -2);       // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 120, "police", -2);    // 連擊之術
    set_train_with_camp("body iron", 1, 15, 200, "police", -1);       // 鐵塊
    set_train_with_camp("body gang", 0, 20, 140, "police", 0);        // 特殊：鐵塊•剛
    set_train_with_camp("body sui", 0, 21, 140, "police", 0);         // 特殊：鐵塊•碎

    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":10+random(15), "p1":100, "p2":100 ]),   // 黃金
        ([ "type":"eq", "id":21, "amount":1, "p1":80, "p2":100 ]),                 // 布手套
        ([ "type":"eq", "id":31, "amount":1, "p1":70, "p2":100 ]),                 // 犀牛帽
    }) );
    setup();
    set_skill("combat", 180);
    set_skill("dodge", 180);
    set_skill("parry", 200);
    set_skill("heavy hit", 180);
    set_skill("savage hit", 140);
    set_skill("continual hit", 120);
    set_skill("body sui", 200);
    set_skill("body gang", 200);
    set_skill("body iron", 200);
    set_skill("paper step", 120);

    add_temp("apply/exact", 50);       // 命中
    add_temp("apply/evade", 50);       // 迴避
    add_temp("apply/intimidate", 50);  // 攻擊能力
    add_temp("apply/wittiness", 200);  // 防禦能力
    add_temp("apply/con", 30);

    carry_object(__DIR__"eq/pants.c")->wear();
    carry_object(__DIR__"eq/suit.c")->wear();
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 25 + random(6);

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
    msg = "\n\n"HIW+this_object()->query("name")+"不可置信地嘶吼：這不可能的！最強的鐵塊怎麼會被打敗！"NOR"\n\n"NOR;
    msg += HIB"【世界政府】ＣＰ９「六式」高手"+this_object()->query("name")+"("+this_object()->query("id")+")居然被"+enemy->query("name")+"("+enemy->query("id")+")殺死了！\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死布魯諾獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}
