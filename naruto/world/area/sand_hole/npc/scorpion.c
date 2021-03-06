#include <npc.h>
#include <ansi.h>

void do_fight()
{
    int damage;
    object enemy;
    mapping cnd = ([]);

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // 已經中毒就不刺了
    if( enemy->query_condition("scorpion_poison", 1) != 0) return;

    message_vision("\n$N"HIM"將尾部對準$n，忽然爬了過來狠狠的一螫！\n"NOR, this_object(), enemy);
    if( random(500) < random(300) ) {
        message_vision("但是蠍尾只是刺中了$N的衣服，並沒有傷到$N。\n\n", enemy, this_object());
        this_object()->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, this_object());
    message_vision("\t$N唉呦一聲，蠍毒慢慢的流進$N的體內，使$N痛苦不堪。\n\n", enemy, this_object());
    enemy->start_busy(1);

    cnd["name"] = MAG+"蠍毒"+NOR;
    cnd["duration"] = 3;
    cnd["from"] = this_object();

    enemy->set_condition("scorpion_poison", cnd);

    return;
}

void create()
{
    set_name("毒蠍", ({ "scorpion" }) );
    set_level(30);
    set_race("beast");
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("age", 11+random(21));
    set("limbs", ({ "蠍頭", "雙螯", "蠍尾", "肚子", "蠍足" }) );
    set("long", "生活在沙穴地底的劇毒生物，現在似乎被沙盜所飼養。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
       ([ "type":"eq", "id":110, "amount":1, "p1":1, "p2":800 ]),              // 毒蠍雙螯
        ([ "type":"obj", "id":113, "amount":1+random(2), "p1":30, "p2":100 ]), // 毒蠍血清
    }) );
    setup();
    add_temp("apply/hp", 500);
    add_temp("apply/attack", 50);
    // 有調整過 ap, hp, mp 的要 do_heal(), 才能讓狀態補滿
    do_heal();
}
