#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say 嗚吱吱！想不想「加入」我們打撈團隊猿山連合軍？" :),
        (: command, "say 身為人類就是要有夢想阿！嗚吱吱！" :),
        (: command, "say 你說我不是人類！？想嘗嘗我的歌聲嗎！！" :),
    }) );
}

void do_fight()
{
    int exact, evade;
    object enemy;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    if( enemy->is_busy() || this_object()->is_busy() ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->intimidate(this_object(), 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    message_vision("\n$N拿起麥克風大喊："HIG"嘗嘗我的「"HIY"無堅不摧喔喔喔！"HIG"」！\n"NOR+CYN"四周開始傳出惱人的噪音！\n\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n穩定心情，絲毫不受這陣噪音影響。\n\n"NOR, this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    message_vision(CYN"$n被噪音所影響，頭痛欲裂無法行動了！\n\n"NOR, this_object(), enemy);
    this_object()->start_busy(1);
    enemy->start_busy(4);
    return;
}
void create()
{
    set_name("猩猩", ({ "orang" }) );
    set_race("human");
    set_level(47);
    set("title",HIY"猿山連合"NOR);
    set("nickname",HIG"探索王"NOR);
    set("gender", "male");
    set("class","big_sea");
    set("camp", "robber");
    set("age", 39);
    set("long", "坐在船中央的大猩猩，身材似乎是一般人的三倍，他留了一頭長長的\n"
                "頭髮，將坐位後面都蓋住了，手上還拿著麥克風，不知道想做什麼。\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say 我的頭髮可是從出生到現在都沒剪過呢！" :),
        (: to_do_say :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":2+random(4), "p1":30, "p2":100 ]),  // 黃金
        ([ "type":"eq", "id":102, "amount":1, "p1":1, "p2":300 ]),             // 猿猴護腿
        ([ "type":"eq", "id":99, "amount":1, "p1":1, "p2":100 ]),              // 蛙鞋
        ([ "type":"eq", "id":100, "amount":1, "p1":20, "p2":100 ]),            // 潛水衣
    }) );
    setup();
    add_temp("apply/attack", 50);
    add_temp("apply/armor", 100);
}

// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    object test;

    if( arg == "加入" ) {
        if( me->query_class() != "commoner" ) {
            do_chat( ({ 
                (: command, "shake" :),
                (: command, "say 猩猩很聰明的！不歡迎"+me->rank()+"！" :),
            }) );
            return 1;
        }
        if( me->query_temp("quest/mitp") ) {
            do_chat( ({ 
                (: command, "say "+me->query("name")+"已經拿到考卷了阿！" :),
                (: command, "say 拿那麼多張幹麻！嗚吱吱！" :),
            }) );
            return 1;
        }
        test = new(_DIR_AREA_"sifa_isle/npc/item/paper.c");
        if( !objectp(test) ) {
            do_chat( ({
                (: command, "say 糟糕！一不小心把考卷都發光了！" :),
                (: command, "say 快來人再去打撈一些考卷！" :),
            }) );
            return 1;
        }
        if( !test->move(this_object()) ) {
            do_chat( ({ 
                (: command, "ah" :),
                (: command, "say 考卷撈到了嗎？！" :),
            }) );
            destruct(test);
            return 1;
        }
        // 設定玩家暫時變數，以防一直領考卷
        if( test->move(me) ) {
            me->set_temp("quest/mitp", 1);
            // 海賊直接問加入就測驗
            me->set("guild", "piece");
            me->set("title", "海賊測試者");
            do_chat( ({
                (: command, "say 喔喔！既然"+me->query("name")+"有心加入我們猿山連合！" :),
                (: command, "say 那就把這份考卷寫一寫吧！" :),
                (: command, "say 雖然是海軍那邊的試卷，不過被猩猩撈到就屬於猩猩的啦！" :),
                (: command, "say 考卷交給"+me->query("name")+"了！寫完就給猩猩吧。" :),
                (: command, "say 沒全部答對不准加入猿山連合軍！嗚吱吱！" :),
            }) );
        } else if( environment(me)->is_area() ) {
            if( !area_move(environment(me), test, me->query("area_info/x_axis"), me->query("area_info/y_axis")) ) {
                tell_object(me, "出問題啦！快找巫師處理！\n");
                return 1;
            }
            me->set_temp("quest/mitp", 1);
            // 海賊直接問加入就測驗
            me->set("guild", "piece");
            me->set("title", "海賊測試者");
            do_chat( ({
                (: command, "say 喔喔！既然"+me->query("name")+"有心加入我們猿山連合！" :),
                (: command, "say 那就把這份考卷寫一寫吧！" :),
                (: command, "say 雖然是海軍那邊的試卷，不過被猩猩撈到就屬於猩猩的啦！" :),
                (: command, "say "+me->query("name")+"身上太重！考卷猩猩放在地上，寫完就給猩猩吧。" :),
                (: command, "say 沒全部答對不准加入猿山連合軍！嗚吱吱！" :),
            }) );
            return 1;
        } else {
            destruct(test);
            return 0;
        }
    }
    return 1;
}
int accept_object(object me, object item)
{
    int score;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( item->is_test_paper() != "piece" ) return 0;

    if( me->query("guild") != "piece" ) {
        message_vision("$N說道﹕"HIG"$n是從其他地方逃來的吧！$N不收你！\n"NOR, this_object(), me);
        return 0;
    }
    if( me->query_class() != "commoner" ) {
        message_vision("$N說道﹕"HIG"$n已經有職業了吧！？\n"NOR, this_object(), me);
        message_vision("$N說道﹕"HIG"當$N這麼好騙嗎！\n"NOR, this_object(), me);
        return 0;
    }
    score = item->do_check();
    message_vision("$N盯著考卷猛看...似乎連自己都不太清楚答案...\n", this_object(), item);

    if( score != 100 ) {
        message_vision("$N說道﹕"HIG"$n真是太丟猩猩的臉了！\n"NOR, this_object(), me);
        message_vision("$N說道﹕"HIG"只考"+chinese_number(score)+"分也想加入猿山連合？\n"NOR, this_object(), me);
        return 0;
    }
    message_vision("$N說道﹕"HIG"嗚吱吱！寫的太棒啦！\n"NOR, this_object(), me);
    message_vision("$N說道﹕"HIG"像$n這種人材一定要加入我們猿山連合軍的啦！\n"NOR, this_object(), me);
    me->set("title", "猿山連合軍");
    me->set_level(1);
    me->addCamp("robber");  // 增加海賊陣營
    me->set_class("little_sea");
    // 使用 do_chat 來延遲呼叫 destruct 先讓 give 動作完成
    do_chat( ({
        (: destruct, item :),
        (: command, "say 加入之後要稱呼猩猩為大園長喔！" :),
        (: command, "say 什麼？想要大園長教你戰鬥的技巧嗎？" :),
        (: command, "laugh" :),
        (: command, "say 大園長的招術可是沒那麼容易學的！" :),
        (: command, "ah" :),
        (: command, "say "+this_player()->query("name")+"可以去隔壁黃金梅莉號看看！他們會教你戰鬥技巧的！嗚吱吱！" :),
    }) );
    return 1;
}