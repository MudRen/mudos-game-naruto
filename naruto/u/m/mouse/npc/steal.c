#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void do_fight()
{
    int bank;
    object enemy;
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    bank = random(999) + 601;
    message_vision("$N"HIY"拿出一台轉帳機，偷了"NOR"$n"HIY"的信用卡狂刷不停！\n"NOR, this_object(), enemy);
    if( enemy->query("bank") <= 1000 ) {
        message_vision("$N碎碎唸著﹕"HIG"$n"NOR+HIG"真窮阿...還沒刷就透支了。\n"NOR, this_object(), enemy);
        return;
    }
    message_vision(HIG"銀行通知$n被扣款("HIY+bank+HIG")兩銀子！\n"NOR, this_object(), enemy);
    enemy->add("bank", -bank);
    this_object()->add("bank", bank);
    return;
}
void do_money()
{
    int i;
    i = random(200) - 100;
    if( this_object()->query("bank") > 5000 && (this_object()->query_stat_current("hp") < this_object()->query_stat_maximum("hp")*0.5) ) {
        message_vision("$N大喊著："HIG"我有錢了！快來幫我療傷！\n"NOR, this_object());
        message_vision(HIW"突然"HIW""BLK"怪醫黑傑克"HIW"出現在這裡，用飛快的手術治好了"NOR"$N"HIW"身上的傷痛。\n"NOR, this_object());
        this_object()->heal_stat("hp", 9999);
        this_object()->add("bank", -5000);
        return;
    } else if( this_object()->query_stat_current("hp") < this_object()->query_stat_maximum("hp")*0.3 ) {
        message_vision("$N痛苦的喊著："HIG"有誰能救救我阿！\n"NOR, this_object());
        return;
    }
    message_vision(CYN"$N口中喃喃自語不知道在說什麼。\n"NOR, this_object());
    return;
}
void create()
{
    set_name("劫財童子", ({ "Steal Child", "child" }));
    set("nickname",HIR"奉天劫財"NOR);
    set("title",HIK"沒錢搶錢"NOR);
    set_race("human");
    set_level(15+random(5));
    set("age", 10);
    set("long", "全身破破爛爛的，一直盯著你的錢包猛看。\n");
    set("guard_exit", ({ 
        "west", "east", "north", "south", "up", "down",
        "northeast", "northwest", "southeast", "southwest"
    }));
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command, "coco" :),
        (: do_fight :),
        (: do_money :),
    }) );
    setup();
}
int do_guard_exit(int x, int y, string exit)
{
    message_vision("$N伸出腳把$n絆倒在地上。\n", this_object(), this_player());
    do_chat(({ 
       NOR"劫財童子說道﹕"HIG"救濟貧苦∼人人有則∼\n"NOR,
       NOR"劫財童子說道﹕"HIG"有錢出錢∼沒錢還是要出錢∼\n"NOR,
    }));
    return 1;
}
void die()
{
    int bank;
    object enemy;
    enemy = this_object()->last_damage_giver();
    if( !enemy ) {
        ::die();
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            ::die();
            return;
        } else
        if( environment(enemy) != environment(this_object()) ) {
            ::die();
            return;
        }
    }
    message_vision("$N大叫著﹕"HIG"死了也要帶$n的錢下去陪葬！\n"NOR, this_object(), enemy);
    if( enemy->query("bank") <= 10000 ) {
        message_vision("$N用最後一口氣說﹕"HIG"居然沒錢可以偷！...太失敗啦∼\n"NOR, this_object(), enemy);
        ::die();
        return;
    }
    message_vision(HIG"銀行通知$n被扣款("HIY"10000"HIG")兩銀子！\n"NOR, this_object(), enemy);
    enemy->add("bank", -10000);
    ::die();
    return;
}
