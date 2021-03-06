#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;
int i;

string *def_msg = ({
        "$n嚇的滿頭大汗，好不容易躲開了攻擊！",
        "$n一個側身隔開攻擊，卻仍被轟的老遠！所幸沒有受傷。",
        "$n向後狂奔數丈，才安心的停下腳步。",
});
string *atk_msg = ({
        "「碰」一聲巨響，$n哀嚎一聲，飛落數丈之外。",
        "「磅」一聲，$n像被全壘打般飛向遙遠的一端。",
        "$n躺在地上打滾，難過的不停抽搐，似乎非常痛苦。",
});

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
    if(i < 10) {
    message_vision("$N說道﹕"HIG"還不夠力阿，再多轉幾圈好了。\n"NOR, this_object());
    return;
    }
    message_vision("$N活動活動筋骨，忽然一記"HIW"「"HIR"螺旋搏擊"HIW"」"NOR"手部快速旋轉著擊向$n！\n", this_object(), enemy);
    damage = this_object()->query_ability("attack") - random(enemy->query_ability("defend"));
    if( damage < 0) {
        damage = 0;
    }
    if( random(enemy->query_ability("evade")) > this_object()->query_ability("evade")) {
        msg = def_msg[random(sizeof(def_msg))];
        message_vision("        "+msg+"(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        i = 0;
        return;
    }
    damage += i*i;
    msg = atk_msg[random(sizeof(atk_msg))];
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        "+msg+"("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    enemy->start_busy(3);
    i = 0;
    return;
}
void do_mass()
{
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
    i = i+1+random(3);
    message_vision(CYN"$N快速旋轉著手臂"NOR"("HIY+i+NOR")\n", this_object());
    return;
}
void create()
{
    set_name("芬克斯", ({ "fancus" }));
    set_race("human");
    set_level(60);
    set("title",HIK"幻影旅團"NOR);
    set("age",25);
    set("long", "眼神銳利、身材高大，看起來非常危險的人物。\n");
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_mass :),
        (: do_mass :),
        (: do_fight :),
        (: do_mass :),
        (: do_mass :),
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
                do_chat((: command, "say 一張就好，多的不要。" :));
                return 0;
            }
            message_vision("$N說道﹕"HIG"好了！要去哪快說吧！\n"NOR, this_object());
            do_chat(({ 
                (: command, "follow " + this_player()->query("id") :),
                (: command, "guard " + this_player()->query("id") :),
            }));
            break;
        default:
            do_chat((: command, "say 這種東西不要給我。" :));
            return 0;
            break;
    }
    return 1;
}
