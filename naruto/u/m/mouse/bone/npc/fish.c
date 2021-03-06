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
    message_vision("$N"HIK"張大嘴巴吐出一團"HIM"紫色毒液"HIK"！\n"NOR, this_object(), enemy);
    damage = random(11)+10;
    if( random(enemy->query_ability("evade")) > 100) {
        message_vision("        $n往旁邊一跳避開了攻擊。(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        「沙∼」地一聲，紫液腐蝕了$n的身體！("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name("沼澤毒魚", ({ "marsh fish", "fish" }) );
    set_level(20);
    set_race("beast");
    set("age", 100+random(501));
    set("long", "全身長滿了奇怪的肉瘤，口中不停的流出紫色液體。\n");
    set("attitude", "aggressive");
    set("chat_chance", 20);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
}
