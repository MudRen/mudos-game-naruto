#include <npc.h>
#include <ansi.h>

void do_fight(object enemy)
{
    int damage, raiseDamage, i, exact;
    object* targets;

    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->exact(this_object(), enemy, 1)/2;
    add_temp("apply/exact", exact);

    message_vision("\n$N"HIM"雙手快速結印，全身氣孔忽然發出陣天鳴聲『"HIY"音之波動"HIM"』！\n"NOR, this_object(), enemy);
    for(i=0;i<sizeof(targets);i++) {
        if( i > 4) break;   // 對五個人有用
        if( !COMBAT_D->isHit(this_object(), targets[i]) ) {
            message_vision("$n向後連退數丈才好不容易離開攻擊範圍！\n", this_object(), targets[i]);
            this_object()->start_busy(1);
        } else {
            raiseDamage = 700;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            if( damage <= 500 ) damage = 350 + random(150);

            targets[i]->damage_stat("hp", damage, this_object());
            message_vision( sprintf("一聲震耳巨響壓的$n喘不過氣來，四周聲音完全消失(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
            targets[i]->start_busy(2);
        }
    }
    add_temp("apply/exact", -exact);
    message_vision("\n", this_object());
}
void do_heal()
{
    if( this_object()->query_stat("hp") > 2000 ) return;
    message_vision("$N"HIM"將查克拉施於長笛之中緩緩吹奏，身上的傷口快速回復了！\n"NOR, this_object());
    this_object()->heal_stat("hp", 9999);
    return;
}
void create()
{
    set_name("悠音", ({ "yu in", "in" }) );
    set_level(40);
    set_class("superior");
    set_race("human");
    set("gender", "female");
    set("age", 25);
    set("title",HIM"音之上忍"NOR);
    set("long", "身穿著上忍衣服，看起來非常不好惹的樣子。\n");
    set("guard_exit", ({ "east" })); // 守著出口
    set("chat_chance", 100);
    set("chat_msg", ({
        (: do_heal :),
    }));
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":1+random(2), "p1":60, "p2":100 ]),   // 黃金
        ([ "type":"eq", "id":89, "amount":1, "p1":1, "p2":150 ]),               // 護腰
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":150 ]),               // 護額
    }) );
    setup();
    set_stat_current("hp", 5400);
    set_stat_maximum("hp", 5400);
}
int give_check(object ob)
{
    if( ob->id("__WHEYA__") ) return 1;   // 輝夜之證
    else return 0;
}
int do_guard_exit(int x, int y, string exit)
{
    if( this_player()->query_temp("quest/goinhole") != 1) {
        message_vision("$n伸出手擋住$N的去路。\n", this_player(), this_object());
        do_chat((: command, "say 拿出輝夜之證來，不然別想通過這裡。":));
        return 1;
    }
    this_player()->delete_temp("quest/goinhole");
    return 0;
}
int accept_object(object me, object ob)
{
    object item;

    if( is_busy() ) {
        do_chat((: command, "say 等前一位通過再說。" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 哼！找死！" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( this_player()->query_temp("quest/goinhole") == 1) {
                message_vision("$N疑惑的看著$n說道﹕"HIG"你已經給過了，快過去吧。\n"NOR, this_object(), this_player());
                return 0;
            }
            message_vision("$N接過$n的"HIR"輝夜之證"NOR"說道﹕"HIG"好了，你過去吧。\n"NOR, this_object(), this_player());
            this_player()->add_temp("quest/goinhole", 1);
            do_chat(((: destruct, ob :)));
            break;
        default:
            do_chat((: command, "say 只有輝夜之證能通過這裡。" :));
            return 0;
            break;
    }
    return 1;
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = random(2) + 1;

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
    // 寵物殺死算主人的
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"HIM+this_object()->query("name")+"說道：大蛇丸大人，請恕我沒有完成應盡的本份！\n"NOR;
    msg += HIR"\n"HIR"【社會新聞】"+this_object()->query("name")+"("+this_object()->query("id")+")死於"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")之手了！\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死"+this_object()->query("name")+"獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}