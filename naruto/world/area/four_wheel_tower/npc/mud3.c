#include <npc.h>
#include <ansi.h>
#include "sand_sk.h"

void create()
{
    set_name("泥怪王", ({ "king mud", "mud", "_KING_ONE_" }) );
    set_level(30);
    set_race("human");
    set("gender", "male");
    set("title", "泥漿噴泉");
    set("nickname", HIK"壹"NOR);
    set("limbs", ({ "爛泥", "觸手", "黏液", "眼睛", "嘴巴" }) );
    set("age", 2000);
    set("long", "泥巴之王，比其他泥巴怪擁有更完整的身體，而且身體部份部位還會\n"
                "像泥漿噴泉一樣噴出一些爛泥，有夠噁心的。\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        CYN"泥怪王的身子像個泥火山不停噴漿...\n"NOR,
    }));
    set("chat_chance_combat", 35);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":151, "amount":random(20)+1, "p1":80, "p2":100 ]),  // 廢土
        ([ "type":"obj", "id":152, "amount":random(10)+1, "p1":80, "p2":100 ]),  // 塵埃
        ([ "type":"obj", "id":153, "amount":random(3)+1, "p1":80, "p2":100 ]),   // 爛果
        ([ "type":"obj", "id":156, "amount":random(5)+1, "p1":80, "p2":100 ]),   // 碎石
        ([ "type":"obj", "id":154, "amount":random(5)+1, "p1":30, "p2":100 ]),   // 沙礫
        ([ "type":"obj", "id":149, "amount":random(2)+1, "p1":10, "p2":100 ]),   // 結塊
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
    msg = "\n"HIW"【四方之塔】"HIY"琥珀之塔一樓人去樓空，"+enemy->query("name")+"居然將泥火山景觀一樓守塔者"NOR"「"+this_object()->query("title")+"」"HIY+this_object()->query("name")+"殺死了！\n\n"NOR;

    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    if( killer->query_level() - 10 <= this_object()->query_level() ) {
        if( random(100) < 5 ) {
            tell_object(killer, HIY"(因為你殺死"+this_object()->query("name")+"獲得了 1 點兌換點數。)\n"NOR);
            killer->add("exchange", 1);
        }
        tell_object(killer, HIR"\n你殺死了"+this_object()->query("name")+"而額外獲得了 "HIY+i+HIR" 點學點。\n"NOR);
        killer->add_point("learn", i);
    }
    if( random(10) > 4 ) {
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
