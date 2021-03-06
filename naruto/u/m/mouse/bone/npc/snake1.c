#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight()
{
    int damage;
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
    if( this_object()->query_temp("quest/snake_blade") == 1) {
    return;
    }
    message_vision("$N"HIG"拿著彎刀朝地上一掃，捲起地上草皮石塊攻擊"NOR"$n"HIG"。\n"NOR, this_object(), enemy);
    damage = 20+random(36);
    if( random(enemy->query_ability("intimidate")) > 120) {
        message_vision("        $n將石塊草皮打散，繼續攻擊$N。(0)"+report_status(enemy)+"", this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        石塊打的$n手忙腳亂，不少地方都被砸傷。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    this_object()->add_temp("quest/snake_blade", 1);
    call_out("blade_1",5,this_object(),enemy);
    return;
}
void blade_1()
{
    int damage;
    object enemy;
    enemy = this_object()->query_opponent();
    this_object()->delete_temp("quest/snake_blade");
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    damage = random(this_object()->query_ability("attack")) + random(101) + 30;
    damage -= random(enemy->query_ability("defend")) + random(150);
    message_vision("$N"HIY"趁石塊擊中"NOR"$n"HIY"之時，順勢從後方一刀劈來！\n"NOR, this_object(), enemy);
    if( damage <= 0 || random(enemy->query_ability("intimidate")) > 80) {
        message_vision("        $n反應得當，順利化解此招。(0)"+report_status(enemy)+"\n"NOR, this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n「刷」地一聲被彎刀砍中，造成二次傷害！("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void create()
{
    set_name("戰蛇", ({ "warrior snake", "snake" }) );
    set_race("human");
    set("gender", "male");
    set_level(33+random(3));
    set("age", 20+random(21));
    set("limbs", ({ "蛇頭", "蛇尾", "腹部", "胸口", "腳部", "肩膀", "腰部" }) );
    set("title",HIG"蛇族戰士"NOR);
    set("long", "手持彎刀，拿著一柄圓形劍盾的蛇人。\n");
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: command, "say 殺！不留活口！" :),
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // 蛇神項鍊
        ([ "type":"wp", "id":49, "amount":1, "p1":1, "p2":300 ]),     // 彎刀
        ([ "type":"wp", "id":48, "amount":1, "p1":1, "p2":275 ]),     // 盾劍
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // 蛇膽
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // 蛇皮
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // 蛇牙
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // 蛇毒
    }) );
    setup();
}
