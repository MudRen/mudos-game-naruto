#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void do_fight()
{
    int damage, raiseDamage, exact, evade;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( random(1000) ) {
        case 0..450:
            exact = this_object()->query_level();
            evade = enemy->query_level();

            this_object()->damage_stat("mp", 20, this_object());
            message_vision("\n$N"HIR"拿起木杖隨手一揮，快速打出火彈朝"NOR"$n"HIR"擲來！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("但是$N似乎實戰能力不足，射出的火彈飛到老遠去了。\n\n", this_object(), enemy);
                this_object()->start_busy(1);
                return;
            }
            raiseDamage = 250;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            if( damage < 100 ) damage = 50 + random(50);

            // 傷害盾吸收
            damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("「轟隆」一聲，只聽見$n一聲慘叫，一位裸體的黑人就誕生了(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            break;
        case 451..550:
            exact = this_object()->query_level();
            evade = enemy->query_level()/2;

            this_object()->damage_stat("mp", 30, this_object());
            message_vision("\n$N"HIK"陰森的拿起木杖，唸起蛇神咒文...似乎有什麼大事要發生了...\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$n天空忽然一片漆黑，但是過了很久卻只有一片樹葉落了下來...\n\n", this_object(), enemy);
                return;
            }
            raiseDamage = 650;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            if( damage < 200 ) damage = 150 + random(50);

            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("天空忽然一片漆黑，在轟隆巨響中，一道黑色的閃光就在瞬間擊中$n的肉體(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
            break;
        case 551..999:
            exact = this_object()->query_level();
            evade = enemy->query_level()/2;

            this_object()->damage_stat("mp", 15, this_object());
            message_vision("\n$N"HIC"拿起木杖朝"NOR"$n"HIC"一指！發出兩道冰刺順著木杖方向戳去！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("只見冰刺飛到一半卻忽然失去了力量，直接扎在地上。\n\n", this_object(), enemy);
                return;
            }
            raiseDamage = 100;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            // 傷害盾吸收
            damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("「框啷」一聲，冰刺戳在$n的身上，凍的$n直發抖(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
            break;
    }
    return;
}

void create()
{
    set_name("巫蛇", ({ "wizard snake", "snake" }) );
    set_race("human");
    set("gender", "female");
    set_level(33+random(3));
    set("age", 20+random(41));
    set("limbs", ({ "蛇頭", "蛇尾", "腹部", "胸口", "腳部", "肩膀", "腰部" }) );
    set("title",HIG"蛇族巫師"NOR);
    set("long", "手持一根木杖的蛇人，頭上帶著一塊布遮住牠的表情。\n");
    set("camp", "snaker");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command, "say 給予蛇族強大的力量！" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // 蛇神項鍊
        ([ "type":"wp", "id":51, "amount":1, "p1":1, "p2":200 ]),     // 蛇杖
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // 蛇膽
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // 蛇皮
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // 蛇牙
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // 蛇毒
    }) );
    setup();
}