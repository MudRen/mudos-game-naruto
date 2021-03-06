#include <npc.h>
#include <ansi.h>

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight(string arg)
{
    // 被封印的吹飛pf
    string area_file = "/open/world/area/thorn_pine/waterfall.c";
    int damage;
    object enemy, area;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N"HIY"張大翅膀振動！發出狂風襲向"NOR"$n"HIY"！\n"NOR, this_object(), enemy);
    damage = 50+random(151);
    if( random(enemy->query_ability("wittiness")) > 200 ) {
        message_vision("        $n站穩了身子沒被狂風所吹動！(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    if( !objectp(area = load_object(area_file)) ) {
        enemy->damage_stat("hp", damage, this_object());
        message_vision("        $n被吹了起來，重重跌在地上。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        enemy->start_busy(1);
        return;
    }
    if( !area->is_area() ) {
        enemy->damage_stat("hp", damage, this_object());
        message_vision("        $n被吹了起來，重重跌在地上。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        enemy->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, this_object());
    message_vision("        $n身子被狂風所捲起，遠遠的飛了出去。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    if( !area_move(area, enemy, random(20), 26+random(15)) ) {
        enemy->damage_stat("hp", damage, this_object());
        message_vision("        $n被風勢影響，最後重重的跌落在原地。", this_object(), enemy);
        enemy->start_busy(1);
        return;
    }
    message_vision("$N從天上掉了下來，一時無法移動。\n", enemy);
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name("蒼之梟", ({ "fly owl", "owl" }) );
    set_race("beast");
    set("title", HIY"小型翼王類" NOR);
    set_level(40+random(6));
    set("age", 100+random(251));
    set("long", @LONG
不知從何處飛來的王系有翼鳥，生性喜歡噪音大、上升氣流強烈的地
方，這轟天瀑布就正好成為了牠們最佳的棲息之地。此種鳥類因為尋
找棲息地非常不容易，所以每當牠們找到一處棲息之地後，便會竭盡
所能的趕走原本棲息在當地的任何生物。
LONG);

    set("limbs", ({ "頭部", "身體", "肚子", "翅膀", "梟爪", "梟嘴", "背部" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":84, "amount":1, "p1":1, "p2":600 ]),   // 梟之翼
        ([ "type":"eq", "id":83, "amount":1, "p1":1, "p2":100 ]),   // 巨梟爪
        ([ "type":"obj", "id":67, "amount":1, "p1":20, "p2":100 ]), // 梟之眼
        ([ "type":"obj", "id":68, "amount":1+random(5), "p1":40, "p2":100 ]), // 梟羽
        ([ "type":"eq", "id":63, "amount":1, "p1":30, "p2":100 ]),  // 鳥嘴
        ([ "type":"obj", "id":27, "amount":5+random(16), "p1":100, "p2":100 ]), // 羽毛
    }) );
    setup();
}
