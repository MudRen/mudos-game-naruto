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
    message_vision("$N"HIW"拿起長槍一抖，如靈蛇般的戳向"NOR"$n"HIW"四肢關節處！\n"NOR, this_object(), enemy);
    damage = this_object()->query_ability("attack") + this_object()->query_ability("intimidate") + random(100);
    damage -= random(enemy->query_ability("defend") + enemy->query_ability("wittiness"));
    if( random(this_object()->query_ability("exact")) - random(enemy->query_ability("evade")) <= 0) {
        message_vision("        $n快速的閃過了攻擊！真是好險。(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n被戳出四個血洞，一時間難以反擊。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    enemy->start_busy(1);
    return;
}
void create()
{
    set_name("蛇皇", ({ "snake king", "snake", "king" }) );
    set_race("human");
    set("gender", "male");
    set_level(45);
    set("age", 35);
    set("limbs", ({ "蛇頭", "蛇尾", "腹部", "胸口", "腳部", "肩膀", "腰部" }) );
    set("title",HIW"蛇族皇帝"NOR);
    set("long", "身穿一件長披風，手上拿著一把白色的長槍，看起來很威風。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say 蛇族是最偉大的種族！" :),
        (: command, "nomatch" :),
        (: command, "say 總有一天天下會以蛇族為尊！" :),
    }));
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":5, "p2":100 ]),     // 蛇神項鍊
        ([ "type":"wp", "id":47, "amount":1, "p1":1, "p2":800 ]),     // 白皇蛇槍
        ([ "type":"wp", "id":49, "amount":1, "p1":15, "p2":100 ]),    // 彎刀
        ([ "type":"wp", "id":48, "amount":1, "p1":20, "p2":100 ]),    // 盾劍
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // 蛇膽
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // 蛇皮
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // 蛇牙
        ([ "type":"obj", "id":82, "amount":1, "p1":20, "p2":100 ]),   // 蛇毒
    }) );
    setup();
}
