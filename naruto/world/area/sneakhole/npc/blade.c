#include <ansi.h>
#include <npc.h>

void do_fight()
{
    object enemy;
    int damage, raiseDamage, exact, evade;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->wittiness(this_object(), 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 10, this_object());
    message_vision("\n$N"HIG"露出兩對尖銳如刀鋒的前腳，忽然一個飛身撲向$n！\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n一腳朝$N肚子踢了下去，痛的$N倒在地上奇奇叫。\n\n", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    raiseDamage = 150;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 20 ) damage = 10 + random(10);

    // 傷害盾吸收
    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("$n閃避不及被利腳劃出了幾道口子，傷口雖然細小卻難已止血(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name(HIK"利刃蜘蛛"NOR, ({ "blade spider", "spider" }) );
    set_race("beast");
    set("title","陰影蜘蛛");
    set_level(28);
    set("long", "八隻腳都如刀刃一般尖利的巨型突變蜘蛛。\n");
    set("limbs", ({ "蜘頭", "身體", "腹部", "蛛腿" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),       // 蜘蛛腿
        ([ "type":"obj", "id":81, "amount":1, "p1":1, "p2":125 ]),        // 蜘蛛標本
        ([ "type":"obj", "id":80, "amount":1, "p1":3, "p2":100 ]),        // 黏液
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // 查克拉丸
        ([ "type":"eq", "id":91, "amount":1, "p1":1, "p2":600 ]),         // 開襠褲
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // 體力丸
    }) );
    setup();
    add_temp("apply/attack", 50);
    set_skill("combat", 130);
    set_skill("dodge", 130);
    set_skill("parry", 130);
    set_skill("savage hit", 130);
    set_skill("heavy hit", 130);
    set_skill("continual hit", 130);
}
