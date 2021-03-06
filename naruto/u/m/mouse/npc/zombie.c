#include <npc.h>
#include <ansi.h>

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$N" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$N" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$N" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_vemon(object enemy)
{
    int damage, i;
    object* targets;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    message_vision("$N"HIM"噴出大量的屍毒，影響四周的敵人！\n"NOR, this_object());
    for(i=0;i<sizeof(targets);i++) {
        if( i > 2) break;   // 對三個人有用
        damage = random(this_object()->query_attr("str")) + random(this_object()->query_attr("con"));
        if( random(targets[i]->query_skill("dodge")) > random(this_object()->query_skill("dodge"))) {
            message_vision("        $N迅速的離開了屍毒的範圍！(0)"+report_status(targets[i])+"", targets[i], this_object());
            this_object()->start_busy(1);
        } else {
            targets[i]->damage_stat("hp", damage, this_object());
            message_vision("        $N吸入了大量的屍毒，臉色發紫不停的嘔吐著。("+damage+")"+report_status(targets[i])+"", targets[i], this_object());
        }
    }
}
void check_hp()
{
    if( this_object()->query_stat_current("hp") <= 10 ) {
        message_vision(HIK"\n$N承受不住攻擊，「砰」地一聲化為塵土了。\n"NOR, this_object());
        destruct(this_object());
    }
}
void create()
{
    set_name("殭屍", ({ "zombie" }));
    set_race("beast");
    set("no_zombie", 1);
    set("long", "身體沒有一個地方是完整的，看起來就像一具屍體。\n");
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
       (: do_vemon :),
    }) );
    set("chat_msg", 100);
    set("chat_msg", ({
       (: check_hp :),
    }));
    call_out("die_1", random(100)+200, this_object());
    setup();
}
void die_1()
{
    message_vision(HIY"符咒的能量漸漸消去，"NOR"$N"HIY"化為灰塵回歸大地。\n"NOR, this_object());
    destruct(this_object());
    return;
}
void unconcious()
{
    this_object()->die();
    return;
}
void die()
{
    message_vision(HIK"\n$N承受不住攻擊，「砰」地一聲化為塵土了。\n"NOR, this_object());
    destruct(this_object());
    return;
}
