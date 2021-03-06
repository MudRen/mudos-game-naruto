#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

void do_fight()
{
    int damage, raiseDamage, exact, evade;
    object enemy;
    string msg;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->intimidate(this_object(), 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 10, this_object());
    message_vision("\n$N從腰間拿出一把笛子開始吹奏，四周傳出優美的旋律...\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("但是$n絲毫不在意音樂，繼續攻擊$N，$N也只好收起笛子。\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    raiseDamage = 250;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 50 ) damage = 20 + random(30);

    // 傷害盾吸收
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("正當$n陶醉在音樂中時，音樂忽然一個岔音，一柄吹針射中了$n(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name("音隱忍者", ({ "ninja" }));
    set_race("human");
    set_level(27);
    set("gender", "male");
    set("nickname",HIB"下忍"NOR);
    set("age", 10+random(51));
    set("camp", "music");
    set("long", "音隱村的下忍，正在這裡對抗毒蜘蛛與訓練。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: command, "say 快點將毒蜘蛛清光！" :),
        (: command, "say 必須完成大蛇丸大人指定的任務！" :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":5, "amount":1, "p1":10, "p2":100 ]),              // 苦無
        ([ "type":"obj", "id":29, "amount":50+random(50), "p1":60, "p2":100 ]),// 銀子
        ([ "type":"food", "id":51, "amount":1, "p1":3, "p2":100 ]),            // 燒賣
        ([ "type":"food", "id":10, "amount":1, "p1":2, "p2":100 ]),            // 豚骨
        ([ "type":"food", "id":11, "amount":1, "p1":1, "p2":100 ]),            // 正油
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":600 ]),              // 護額
    }) );
    setup();
    // 增強
    add_temp("apply/armor", 20);
}
