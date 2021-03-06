#include <ansi.h>
#include <npc.h>

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
    object enemy;
    int damage;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    damage = random(this_object()->query_ability("attack") + this_object()->query_ability("intimidate")) + random(20) + 1;
    damage -= random(enemy->query_ability("defend") + enemy->query_ability("wittiness"));
    message_vision("$N"HIG"身子一縮，整個飛了起來撲向$n！\n"NOR, this_object(), enemy);
    if( damage <= 0 || random(enemy->query_ability("intimidate")) > 80) {
        message_vision("        $n一腳朝$N肚子踢了下去，痛的$N奇奇叫。"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
   message_vision("        $n閃避不及被利腳劃出了幾道口子。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void create()
{
    set_name(HIK"利刃蜘蛛"NOR, ({ "blade spider", "spider" }) );
    set_race("beast");
    set("title","陰影蜘蛛");
    set_level(28);
    set("long", "八隻腳都如刀刃一般尖利的巨型突變蜘蛛。\n");
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
        ([ "type":"obj", "id":81, "amount":1, "p1":30, "p2":100 ]),       // 蜘蛛標本
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
