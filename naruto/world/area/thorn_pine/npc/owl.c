#include <npc.h>
#include <ansi.h>

void do_fight(string arg)
{
    int damage, raiseDamage, exact, evade;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->evade(this_object(), enemy, 1);
    evade = COMBAT_D->evade(enemy, this_object(), 1);

    this_object()->damage_stat("mp", 30, this_object());
    message_vision("\n$N不停地振動雙翼，發出強烈的旋風！"HIC"「烈暴風」"NOR"快速的吹向$n！\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("旋風從$n的身上卷去，但是$n靠著驚人的意志力撐住了。\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    raiseDamage = 750;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    add_temp("apply/attack", -raiseDamage);

    if( damage < 300 ) damage = 200 + random(100);

    enemy->receive_damage(damage, this_object());
    message_vision( sprintf("旋風直接將$n卷至空中，$N便順勢展開一連串的突擊(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    enemy->start_busy(1);
    return;
}
void create()
{
    set_name("蒼之梟", ({ "fly owl", "owl" }) );
    set_race("beast");
    set("title", HIY"小型翼王類" NOR);
    set_level(40+random(6));
    set("age", 100+random(251));
    set("camp", "owl");
    set("long", @LONG
不知從何處飛來的王系有翼鳥，生性喜歡噪音大、上升氣流強烈的地
方，這轟天瀑布就正好成為了牠們最佳的棲息之地。此種鳥類因為尋
找棲息地非常不容易，所以每當牠們找到一處棲息之地後，便會竭盡
所能的趕走原本棲息在當地的任何生物。
LONG);

    set("limbs", ({ "頭部", "身體", "肚子", "翅膀", "梟爪", "梟嘴", "背部" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
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