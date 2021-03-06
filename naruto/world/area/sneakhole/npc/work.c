#include <ansi.h>
#include <npc.h>

void do_fight()
{
    object enemy;
    int exact, evade;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if(enemy->is_busy()) {
        message_vision(CYN"$N發出「奇奇奇」的怪聲。\n"NOR, this_object(), enemy);
        return;
    }
    exact = COMBAT_D->intimidate(this_object(), 1);
    evade = COMBAT_D->intimidate(enemy, 1);

    message_vision("\n$N"HIW"八腳一蹬，快速跳到$n面前，噴出許多白絲纏住$n！\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n發覺事情不對，手忙腳亂的將白絲撥開躲的遠遠地。\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    } else {
        message_vision("$n不以為異的繼續攻擊，結果被白絲愈纏愈緊！無法行動了。\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        enemy->start_busy(4);
    }
    return;
}
void create()
{
    set_name(HIK"工程蜘蛛"NOR, ({ "work spider", "spider" }) );
    set_race("beast");
    set("title","陰影蜘蛛");
    set_level(27);
    set("long", "一隻看起來頭部特別肥大的突變蜘蛛。\n");
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
        ([ "type":"obj", "id":81, "amount":1, "p1":1, "p2":150 ]),        // 蜘蛛標本
        ([ "type":"obj", "id":80, "amount":1, "p1":2, "p2":100 ]),        // 黏液
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // 查克拉丸
        ([ "type":"eq", "id":91, "amount":1, "p1":1, "p2":600 ]),         // 開襠褲
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // 體力丸
    }) );
    setup();
    add_temp("apply/attack", 30);
    set_skill("combat", 130);
    set_skill("dodge", 130);
    set_skill("parry", 130);
    set_skill("savage hit", 130);
    set_skill("heavy hit", 130);
    set_skill("continual hit", 130);
}
