#include <npc.h>
#include <ansi.h>
#include "fire_sk.h"

void create()
{
    set_name("美猴王", ({ "beautiful monkey", "monkey", "_KING_TWO_" }) );
    set_level(40);
    set_race("human");
    set("gender", "male");
    set("title", HIR"美•登峰造極"NOR);
    set("nickname", HIY"貳"NOR);
    set("limbs", ({ "猴頭", "火臂", "火尾", "胸口", "猴腳", "肩膀", "腰部", "火毛" }) );
    set("age", 3000);
    set("long", "壞猴子王，穿了一堆不知道從哪裡搶來的人類衣服飾品，全身金光閃\n"
                "閃，不過因為這裡地形炎熱，所以大部份衣服都快燒光了。\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        NOR"美猴王"HIR"拿著一面鏡子端詳著自己的容貌...似乎很滿意。\n"NOR,
    }));
    set("chat_chance_combat", 35);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":151, "amount":1+random(15), "p1":80, "p2":100 ]),  // 廢土
        ([ "type":"obj", "id":152, "amount":1+random(25), "p1":80, "p2":100 ]),  // 塵埃
        ([ "type":"obj", "id":153, "amount":1+random(3), "p1":80, "p2":100 ]),   // 爛果
        ([ "type":"obj", "id":156, "amount":1+random(10), "p1":80, "p2":100 ]),  // 碎石
        ([ "type":"obj", "id":148, "amount":1+random(10), "p1":30, "p2":100 ]),  // 炎灰
        ([ "type":"obj", "id":158, "amount":1+random(3), "p1":10, "p2":100 ]),   // 燒土
    }) );
    setup();
    add_temp("apply/attack", 50);
}

void die()
{
    object enemy, killer, *targets;
    int i, ntar, x, y;
    string msg;

    enemy = this_object()->last_damage_giver();

    if( !enemy ) {
        ::die();
        return;
    }
    // 寵物殺死算主人的
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    i = query_level()*10;
    msg = "\n"HIW"【四方之塔】"HIR"紅蓮之塔二樓慘叫一聲，"+enemy->query("name")+"將二樓守塔者"NOR"「"+this_object()->query("title")+"」"HIR+this_object()->query("name")+"給毀容了！\n\n"NOR;

    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    if( killer->query_level() - 10 <= this_object()->query_level() ) {
        if( random(100) < 15 ) {
            tell_object(killer, HIY"(因為你殺死"+this_object()->query("name")+"獲得了 1 點兌換點數。)\n"NOR);
            killer->add("exchange", 1);
        }
        tell_object(killer, HIR"\n你殺死了"+this_object()->query("name")+"而額外獲得了 "HIY+i+HIR" 點學點。\n"NOR);
        killer->add_point("learn", i);
    }
    if( random(10) > 5 ) {
        targets = query_enemy();
        x = random(30);
        y = random(30);

        // 將玩家的所有動作取消然後丟到其他位置去
        // 先指定座標，好讓玩家的寵物也跟著飛過去
        for(ntar=0;ntar<sizeof(targets);ntar++) {
            if( killer->is_busy() ) targets[ntar]->interrupt(targets[ntar], "*unconcious");
            if( userp(targets[ntar]) ) tell_object(targets[ntar], YEL"\n"+this_object()->query("name")+"臨死前用盡最後的力量將你擊飛到火堆中！\n"NOR);
            if( targets[ntar]->is_busy() ) {
                if( userp(targets[ntar]) ) tell_object(killer, "但被你僥倖逃過一劫。\n\n"NOR);
            } else {
                if( !area_move(environment(targets[ntar]), targets[ntar], x, y) ) {
                    if( userp(targets[ntar]) ) tell_object(targets[ntar], "但被你僥倖逃過一劫。\n\n"NOR);
                }
            }
        }
    }
    ::die();
    return;
}
