#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

int i;

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
    if( this_object()->query_temp("quest/force_sk") == 1) {
        message_vision("$N蹲著馬步，一招『"HIR"崩拳"NOR"』打向$n胸口！\n"NOR, this_object(), enemy);
        damage = 20+random(56);
        if( random(enemy->query_ability("intimidate")) > 100) {
            message_vision("        $n以柔剋剛化解了攻勢。(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(2);
            return;
        }
        enemy->damage_stat("hp", damage, this_object());
        message_vision("        $n「碰！」地一聲退後幾步，嘴角還流出鮮血。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        return;
    } else
    if( this_object()->query_temp("quest/psy_sk") == 1) {
        message_vision("$N將念集於雙掌，一式「"HIY"念氣波"NOR"」襲向$n！\n"NOR, this_object(), enemy);
        damage = 20+random(56);
        if( random(enemy->query_ability("intimidate")) > 100) {
            message_vision("        $n輕鬆的將念力打散了。(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(2);
            return;
        }
        enemy->damage_stat("hp", damage, this_object());
        message_vision("        $n「轟！」被衝退了幾步，嘴角還流出鮮血。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        return;
    }
    return;
}
void create()
{
    set_name("豹人罪犯", ({ "bow criminal", "criminal" }));
    set_race("human");
    set_level(25+random(11));
    set("age", 5+random(81));
    set("limbs", ({ "頭部", "身體", "腹部", "腿部", "尾巴", "耳朵", "肩部", "背部" }));
    set("long", "犯了村規的豹人，正在轟天瀑這裡接受處罰。\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: random_move :),
        (: command, "jump 瀑布" :),
        (: command, "climb 瀑布" :),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":45, "amount":1, "p1":20, "p2":100 ]),  // 木劍
        ([ "type":"wp", "id":33, "amount":1, "p1":10, "p2":100 ]),  // 大木棒
        ([ "type":"wp", "id":41, "amount":1, "p1":10, "p2":100 ]),  // 刺木刀
        ([ "type":"wp", "id":39, "amount":1, "p1":1, "p2":100 ]),   // 軟槍
        ([ "type":"wp", "id":36, "amount":1, "p1":1, "p2":150 ]),   // 刻紋劍
    }) );
    i = random(2)+1;
    if( this_object()->query("level") >= 30 ) {
        if( i == 1 ) {
            this_object()->add_temp("quest/force_sk", 1);
        } else
        if( i == 2 ) {
            this_object()->add_temp("quest/psy_sk", 1);
        }
    }
    setup();
}
