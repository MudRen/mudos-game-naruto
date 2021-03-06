#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

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
    string msg;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N朝著$n射出一把飛針！\n"NOR, this_object(), enemy);
    damage = 10+random(51);
    if( random(enemy->query_ability("evade")) > 200) {
        message_vision("        $n快速的從旁邊滾了開來。(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n「噗」的一聲被飛針射中。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void create()
{
    set_name("音隱忍者", ({ "ninja" }));
    set_race("human");
    set_level(27);
    set("gender", "male");
    set("nickname",HIB"下忍"NOR);
    set("age", 10+random(51));
    set("attitude", "aggressive");
    set("long", "音隱村的下忍，正在這裡對抗毒蜘蛛與訓練。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: command, "say 快點將毒蜘蛛清光！" :),
        (: command, "say 必須完成大蛇丸大人指定的任務！" :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":5, "amount":1, "p1":10, "p2":100 ]),              // 苦無
        ([ "type":"obj", "id":29, "amount":50+random(50), "p1":60, "p2":100 ]),// 銀子
        ([ "type":"food", "id":51, "amount":1, "p1":3, "p2":100 ]),            // 燒賣
        ([ "type":"food", "id":10, "amount":1, "p1":2, "p2":100 ]),            // 豚骨
        ([ "type":"food", "id":11, "amount":1, "p1":1, "p2":100 ]),            // 正油
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":600 ]),              // 護額
    }) );
    setup();
}
