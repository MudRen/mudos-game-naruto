#include <ansi.h>
#include <npc.h>

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
    exact = COMBAT_D->wittiness(this_object(), 1)*1.4;
    evade = COMBAT_D->intimidate(enemy, 1);

    this_object()->damage_stat("mp", 10, this_object());
    message_vision("\n$N"HIC"忽然間水性大發，發出叱呼之聲，尾巴一甩不知從何處招來了滾滾大水！\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$N運起自身的內勁，將所有打向自己的大水全部衝散了。\n\n", enemy, this_object());
        this_object()->start_busy(2);
    } else {
        raiseDamage = this_object()->query_level()*10;

        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, 0);
        add_temp("apply/attack", -raiseDamage);

        if( damage < 200 ) damage = 50 + random(150);

        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("$n啪啦一聲被強烈的水波衝到，喉嚨一甜吐出大口鮮血(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        this_object()->start_busy(1);
    }
    return;
}
void create()
{
    set_name("化蛇", ({ "god monster snake", "snake" }));
    set_level(50);
    set_race("beast");
    set("long", "水獸。人面豺身，有翼，蛇行，聲音如叱呼。招大水。 \n");
    set("nickname", HIC"水獸"NOR);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"food", "id":80, "amount":1, "p1":10, "p2":100 ]),     // 水蓮果
        ([ "type":"food", "id":18, "amount":1, "p1":20, "p2":100 ]),     // 大體力丸
        ([ "type":"food", "id":17, "amount":1, "p1":30, "p2":100 ]),     // 體力丸
    }) );
    setup();
}