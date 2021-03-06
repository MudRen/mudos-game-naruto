#include <ansi.h>
#include <npc.h>

void do_fight()
{
    object enemy;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if(enemy->is_busy()) {
        message_vision("$N"CYN"發出「奇奇奇」的怪聲。\n"NOR, this_object(), enemy);
        return;
    }
    message_vision("$N"HIW"突然噴出許多白絲纏住$n！\n"NOR, this_object(), enemy);
    if( random(enemy->query_ability("intimidate")) > 80) {
        message_vision("        $n手忙腳亂的將白絲撥開了。\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    message_vision("        $n被愈纏愈緊！無法行動了。\n", this_object(), enemy);
    enemy->start_busy(2);
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
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),       // 蜘蛛腿
        ([ "type":"obj", "id":81, "amount":1, "p1":25, "p2":100 ]),       // 蜘蛛標本
        ([ "type":"obj", "id":80, "amount":1, "p1":50, "p2":100 ]),       // 黏液
        ([ "type":"food", "id":19, "amount":1, "p1":5, "p2":100 ]),       // 查克拉丸
        ([ "type":"eq", "id":91, "amount":1, "p1":1, "p2":900 ]),         // 開襠褲
        ([ "type":"food", "id":17, "amount":1, "p1":5, "p2":100 ]),       // 體力丸
    }) );
    setup();
    set_skill("combat", 110);
    set_skill("dodge", 110);
    set_skill("parry", 110);
    set_skill("savage hit", 110);
    set_skill("heavy hit", 110);
    set_skill("continual hit", 110);
}
