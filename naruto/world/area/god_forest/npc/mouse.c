#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void do_fight()
{
    mapping cnd = ([]);
    object enemy;
    int exact, evade;

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( enemy->query_condition("firedamage") != 0 ) return;
    exact = COMBAT_D->wittiness(this_object(), 1)*1.5;
    evade = COMBAT_D->intimidate(enemy, 1);

    message_vision("\n$N"HIR"感覺生命受到威脅，全身毛髮豎直，還不時噴出火燄！\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$N到處東躲西閃，總算是沒有成為受害者！\n\n"NOR, enemy, this_object());
    } else {
        cnd["name"] = GRN"燒傷"NOR;
        cnd["duration"] = 10;

        this_object()->damage_stat("mp", 20, this_object());
        enemy->set_condition("firedamage", cnd);
        message_vision("火舌快速地竄向$N，才一會兒就將$N所在的位置燒的一乾二盡。\n\n"NOR, enemy, this_object());
    }
    return;
}
void create()
{
    set_name("火鼠", ({ "god monster mouse", "mouse" }));
    set_level(50);
    set_race("beast");
    set("limbs", ({ "頭部", "鼠毛", "鼠尾", "火刺", "鼻子", "四肢" }) );
    set("long", "生活在火山中，重百斤，毛長接近一米，細如絲，見水即死。用它的\n"
                "毛就可製成「火烷布」\n");

    set("nickname",RED"火光獸"NOR);
    set("set_drop", ({

    }) );
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"food", "id":81, "amount":1, "p1":10, "p2":100 ]),     // 甘露果
        ([ "type":"food", "id":20, "amount":1, "p1":20, "p2":100 ]),     // 大魔力丸
        ([ "type":"food", "id":19, "amount":1, "p1":30, "p2":100 ]),     // 魔力丸
    }) );
    setup();
}