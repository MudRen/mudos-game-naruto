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
    exact = COMBAT_D->intimidate(this_object(), 1)*2;
    evade = COMBAT_D->evade(enemy, this_object(), 1);

    this_object()->damage_stat("mp", 5, this_object());
    message_vision("\n$N"HIR"偷偷摸摸的轉換位置，忽然從草中跳出偷襲"NOR"$n"HIK"！\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n視破了$N的偷襲，避開了攻擊。\n\n", this_object(), enemy);
        return;
    }
    raiseDamage = 250;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 100 ) damage = 50 + random(50);

    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("$n被刀刺了一下卻找不到$N從何處攻擊(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}

void create()
{
    set_name("偷蛇", ({ "thief snake", "snake" }) );
    set_race("human");
    set("gender", "male");
    set_level(33+random(3));
    set("age", 20+random(21));
    set("limbs", ({ "蛇頭", "蛇尾", "腹部", "胸口", "腳部", "肩膀", "腰部" }) );
    set("title",HIG"蛇族襲士"NOR);
    set("long", "手持短刃，身穿黑衣，專門遊走在草叢間。\n");
    set("camp", "snaker");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: command, "peer" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // 蛇神項鍊
        ([ "type":"wp", "id":49, "amount":1, "p1":1, "p2":300 ]),     // 彎刀
        ([ "type":"wp", "id":30, "amount":1, "p1":1, "p2":200 ]),     // 突擊戰刀
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // 蛇膽
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // 蛇皮
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // 蛇牙
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // 蛇毒
    }) );
    setup();
}