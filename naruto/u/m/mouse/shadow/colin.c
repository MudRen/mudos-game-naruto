#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight(object enemy)
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
    message_vision("$N"HIW"雙手關節忽然脫落，開始瘋狂打出「"HIB"雙手機關槍"HIW"」全力掃射四周。\n"NOR, this_object());
    for(i=0;i<sizeof(targets);i++) {
        if( i > 9) break;   // 對十個人有用
        damage = this_object()->query_ability("attack") + random(200);
        damage -= targets[i]->query_ability("defend");
        if( damage <= 0 || random(this_object()->query_ability("exact")) < random(targets[i]->query_ability("evade")) ) {
            message_vision("        但是念彈機關槍沒打中$n....(0)"+report_status(targets[i])+"", this_object(), targets[i]);
        } else {
            targets[i]->damage_stat("hp", damage, targets[i]);
            message_vision( sprintf("        $n被無數念彈打穿了身體，全身沒有一處是完整的！(%d)%s", damage, report_status(targets[i])), this_object(), targets[i]);
        }
    }
}
void create()
{
    set_name("富蘭克林", ({ "fulin colin", "colin" }));
    set_race("human");
    set_level(60);
    set("title",HIK"幻影旅團"NOR);
    set("age",28);
    set("long", "身材壯碩、兩上看不出什麼表情，給人很沉穩的感覺。\n");
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    setup();
}
int give_check(object ob)
{
    if( ob->id("_TEAM_PAPER_") ) return 1;           // 旅團雇請單
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( ob->query_amount() > 1 ) {
                do_chat((: command, "say 只要一張。" :));
                return 0;
            }
            message_vision("$N說道﹕"HIG"好的。\n"NOR, this_object());
            do_chat(({ 
               (: command, "follow " + this_player()->query("id") :),
               (: command, "guard " + this_player()->query("id") :),
            }));
            break;
        default:
            do_chat((: command, "say 不需要。" :));
            return 0;
            break;
    }
    return 1;
}
