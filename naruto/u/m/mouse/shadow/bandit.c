#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;
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
void do_change()
{
    if( i > 0) {
        message_vision(CYN"$N仔細檢查著身上的武器配備。\n"NOR, this_object());
        message_vision("$N大聲回答﹕"HIG"彈夾ok！手榴彈攜帶ok！\n"NOR, this_object());
        i = 0;
        return;
    }
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
    message_vision("$N拿出隨身的"HIK"[烏滋衝鋒槍]"NOR"，配合初級念力打出念能子彈！\n", this_object(), enemy);
    damage = random(this_object()->query_ability("attack"))/2;
    damage += 10;
    if( random(enemy->query_ability("evade")) > 100) {
        message_vision("        $n快速從一旁避開！(0)"+report_status(enemy)+"", this_object(), enemy);
        this_object()->start_busy(2);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n被念能子彈打中，好像受了點傷！("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void do_drop()
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
    message_vision("$N縮著脖子大喊﹕"HIG"快扔手榴彈！\n"NOR, this_object(), enemy);
    call_out("drop_1",10,this_object(),enemy);
}
void drop_1()
{
    int damage;
    object enemy;
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( i > 2) {
        message_vision("$N大聲喊著﹕"HIG"不好啦，手榴彈丟光了！\n"NOR, this_object(), enemy);
        return;
    }
    damage = 100 + random(300);
    message_vision("$N從懷中掏出"HIG"手榴彈"NOR"，拔開引信後朝$n用力擲去！\n"NOR, this_object(), enemy);
    i = i+1;
    if( random(enemy->query_ability("evade")) > 200) {
        message_vision("        $n成功的離開了爆炸範圍！(0)"+report_status(enemy)+"\n"NOR, this_object(), enemy);
        return;
    }
    enemy->damage_stat("hp", damage, enemy);
    message_vision("        $n閃避不急，被爆炸炸傷了！("+damage+")"+report_status(enemy)+"", this_object(), enemy);
    return;
}
void create()
{
    set_name("黑道殺手", ({ "bandit" }));
    set_race("human");
    set_level(40);
    set("title","友克鑫拍賣會");
    set("age", 20+random(50));
    set("long", "十老頭雇用的黑道殺手，專門追殺幻影旅團成員。\n");
    set("chat_chance", 100);
    set("chat_msg", ({
       (: do_change :),
    }) );
    // 戰鬥動作
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: do_drop :),
        (: command, "say 快點散開！散開！" :),
    }) );
    setup();
    set_stat_current("hp", 9999);             // 體力
    set_stat_maximum("hp", 9999);             // 最大值
}
void relay_say(object ob, string arg)
{
    if( arg == "窩金" ) {
        do_chat(({ 
           (: command, "say 幻影旅團成員窩金？！納命來！" :),
           (: command, "kill wowgin" :),
        }));
        return;
    }
    if( arg == "芬克斯" ) {
        do_chat(({ 
           (: command, "say 大家注意！是幻影旅團的芬克斯！" :),
           (: command, "kill fancus" :),
        }));
        return;
    }
    if( arg == "凱特" ) {
        do_chat(({ 
           (: command, "say 為什麼我要攻擊他！不要阿∼" :),
           (: command, "kill kate" :),
        }));
        return;
    }
}
int give_check(object ob)
{
    if( ob->id("_BANDIT_CARD_") ) return 1;           // 殺手雇用卡
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say 我正忙著。" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 戰鬥中。" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( ob->query_amount() > 1 ) {
                do_chat((: command, "say 只要給我一張就夠了。" :));
                return 0;
            }
            message_vision("$N說道﹕"HIG"ＹＡ∼ＳＩＲ！\n"NOR, this_object());
            do_chat(({ 
                (: command, "follow " + this_player()->query("id") :),
                (: command, "guard " + this_player()->query("id") :),
            }));
            break;
        default:
            do_chat((: command, "say ....." :));
            return 0;
            break;
    }
    return 1;
}
