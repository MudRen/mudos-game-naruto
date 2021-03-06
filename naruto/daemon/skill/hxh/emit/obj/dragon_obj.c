#include <npc.h>
#include <ansi.h>

object owner;

// 設定擁有者
int set_owner(object obj)
{
    if( !objectp(obj) ) return 0;
    owner = obj;
}

// 查詢擁有者
object query_owner()
{
    if( !objectp(owner) ) return 0;
    return owner;
}

// 刪除
void do_destruct()
{
    // 已經要消失的寵物就不用一直喊要消失了
    if( query("WILL_DELETE") ) return;

    // 發現寵物召喚過多次會發生保護錯誤
    // 因為離開時沒有刪除寵物保護
    // 所以累積了過多的 guard 資訊  by mouse 2009/2/16
    this_object()->guard_ob(0);
    message_vision("$N"HIY"發出一陣強光，消失在這裡了。\n"NOR, this_object());
    set("WILL_DELETE", 1);

    // 延遲讓一些動作先跑過
    do_chat( ({ (: destruct, this_object() :) }) );
    return;
}

void do_fight()
{
    int damage, raiseDamage;
    object enemy;
    mapping cnd = ([]);

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( query_condition("tiger_cd") ) return;

    this_object()->damage_stat("mp", 50, this_object());
    message_vision("\n$N"HIM"低吼一聲施展"HIW"『"HIC"牙突"HIW"』"HIM"身形有如鬼魅，從非常叼鑽的路境撲向$n！\n"NOR, this_object(), enemy);
    if( !COMBAT_D->isHit(this_object(), enemy) ) {
        message_vision("結果$N看破了攻勢，先行破壞了$n的進攻路境。\n\n", enemy, this_object());
        start_busy(2);
    } else {
        raiseDamage = query_skill("strength")/2 + query_owner()->query_skill("dragon-head draw");

        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/twohanded"));
        add_temp("apply/attack", -raiseDamage);

        if( damage < 150 ) damage = 100 + random(51);

        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("$N伸出龍爪抓住$n被撞飛的身體，張嘴便往$n的肩膀狠狠一咬(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        start_busy(1);
    }
    cnd["name"] = HIC+"(CD)牙突"+NOR;
    cnd["duration"] = 8;

    set_condition("tiger_cd", cnd);
    return;
}

// 隨時檢查擁有者是否有足夠查克拉，並且吸取
void do_check()
{
    string name;
    object ob;

    name = owner->query("id");
    ob = LOGIN_D->find_body(name);

    // 擁有者不在線上，則龍消失
    if( !ob && userp(ob) ) {
        do_destruct();
        return;
    }
    // 不在戰鬥中時自動消失
    if( !this_object()->is_fighting() || !ob->is_fighting() ) {
        do_destruct();
        return;
    }
    // 在不同位置也會消失
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), owner) ) {
            do_destruct();
            return;
        }
    } else {
        if( environment(this_object()) != environment(owner) ) {
            do_destruct();
            return;
        }
    }

    // 成功通過就會使用 pe
    do_chat( ({ (: do_fight :) }) );
    return;
}

// 龍被打死的短CD
void get_CD()
{
    mapping cnd = ([]);

    tell_object(query_owner(), HIR"因為念龍被敵人擊毀，使你的精神受到極大的衝擊！\n"NOR);

    cnd["name"] = HIR+"龍毀神損"+NOR;
    cnd["duration"] = 20;

    query_owner()->set_condition("dragon_draw_cd", cnd);
    return;
}

// 昏倒就直接消失
void unconcious()
{
    get_CD();
    do_destruct();
    return;
}

void die()
{
    get_CD();
    do_destruct();
    return;
}

// 是否接受命令
int accept_order(object who, string cmd)
{
    return 0;  // 分身是不受控制的
}

void create()
{
    set_name("念龍", ({ "dragon", "_DRAGON_NPC_" }));
    set_race("beast");

    set("long", "念力之龍，因放出系能力者高密度的念能力而使破壞力大為提升。\n");
    set("limbs", ({ "龍頭", "身軀", "腹部", "龍尾", "龍爪", "龍鬚" }) ); 
    set("age", 1000 + random(5000));

    // 平時動作：檢查owner還在不在
    set("chat_chance", 50);
    set("chat_msg", ({
        (: do_check :),
    }));

    // 戰鬥時動作：檢查owner還在不在
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_check :),
    }) );
    setup();
}

// 不能fight
int accept_fight(object me, string arg)
{
    return 0;
}

// 不能 kill
int accept_kill(object me, string arg)
{
    remove_all_killer();
    me->remove_killer(this_object());
    return 1;
}