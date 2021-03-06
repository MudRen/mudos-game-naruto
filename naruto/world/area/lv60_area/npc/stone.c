#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void do_fight()
{
    mapping cnd = ([]);
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // 已經中了就不用放
    if( enemy->query_condition("calcification") ) return;
    cnd["name"] = "石灰";
    cnd["duration"] = 1;

    message_vision("$N伸出右手，碰碰碰地噴出數團石灰粉，將$n團團圍住，並且愈包愈緊！\n"NOR, this_object(), enemy);
    message_vision("結果$n被石灰粉所困住，一時間居然無法行動！\n"NOR, this_object(), enemy);
    enemy->set_condition("calcification", cnd);
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name(HIR"火山岩魔"NOR, ({ "fire stone", "stone", "fire" }) );
    set_race("human");
    set("gender", "male");
    set_level(30);
    set("age", 1000 + random(5000));
    set("attitude", "aggressive");
    set("limbs", ({ "身軀", "石臂", "石腿", "石腳", "石掌", "頭部", "眼睛" }) );
    set("title", "石灰石");
    set("long", "身體部份正在燃燒中的巨大魔人，口中發出低沉的吼叫聲。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 25);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":127, "amount":1+random(20), "p1":4, "p2":10 ]),     // 石灰
    }) );
    setup();
}
