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

// 刪除樹人
void do_destruct()
{
    // 已經要消失的寵物就不用一直喊要消失了
    if( query("WILL_DELETE") ) return;

    // 發現寵物召喚過多次會發生保護錯誤
    // 因為離開時沒有刪除寵物保護
    // 所以累積了過多的 guard 資訊  by mouse 2009/2/16
    this_object()->guard_ob(0);
    if( query("WILL_DIE") ) message_vision("$N因為生命力耗盡，變成一堆塵土。\n", this_object());
    else message_vision("因為主人無法提供念力...$N逐漸枯\萎死亡...\n", this_object());
    set("WILL_DELETE", 1);

    // 延遲讓一些動作先跑過
    do_chat( ({ (: destruct, this_object() :) }) );
}

// 隨時檢查擁有者是否有足夠查克拉，並且吸取
void do_check()
{
    int i, ntar;
    object enemy;

    // 擁有者不在線上，則樹人消失
    if( !objectp(owner) ) {
        do_destruct();
        return;
    }

    // 小樹狀態時主人不在身旁直接消失
    if( this_object()->query("change") != 1 ) {
        if( environment(owner)->is_area() ) {
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
    }

    // 在不同位置會自動移到主人旁邊，但是要消耗一些念力
    if( environment(owner)->is_area() ) {
        if( !area_environment(this_object(), owner) ) {
            area_move(environment(owner), this_object(), owner->query("area_info/x_axis"), owner->query("area_info/y_axis"));
            owner->damage_stat("mp", 2);
            message_vision("$N吸收了$n的念力後忽然從地上蹦了出來。\n", this_object(), owner);
            return;
        }
    } else {
        if( environment(this_object()) != environment(owner) ) {
            this_object()->move(environment(owner));
            owner->damage_stat("mp", 2);
            message_vision("$N吸收了$n的念力後忽然從地上蹦了出來。\n", this_object(), owner);
            return;
        }
    }

    if( owner->query_stat("mp") < 10 ) {
        do_destruct();
        return;
    }
    return;
}

// 是否接受命令
int accept_order(object who, string cmd)
{
    return 0;  // 分身是不受控制的
}
void create()
{
    set_name(YEL"小樹"NOR, ({ "tree", "_TREE_" }));
    set_race("human");
    set("long", "一棵尚在栽培中的小樹。\n");
    set("age", random(10) + 1);
    set("limbs", ({ "樹根", "樹枝", "樹葉", "樹皮", "樹莖", "樹幹", "年輪", "樹洞" }) );
    set("chat_chance", 50);
    set("chat_msg", ({
        (: do_check :),
    }));
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_check :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":60, "amount":1, "p1":60, "p2":100 ]),       // 樹枝
    }) );
    setup();
}

void unconcious()
{
    die();
    return;
}

void die()
{
    string name;
    int raiseDamage, damage, sk;
    object enemy, ob;

    enemy = this_object()->last_damage_giver();
    name = owner->query("id");
    ob = LOGIN_D->find_body(name);
    sk = owner->query_skill("born-again branch", 1);

    if( !enemy ) {
        set("WILL_DELETE", 1);
        return;
    }
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) {
            set("WILL_DELETE", 1);
            return;
        } else if( environment(enemy) != environment(this_object()) ) {
            set("WILL_DELETE", 1);
            return;
        }
    }

    // 已經自爆過就不準再爆了
    if( query("WILL_DIE") == 1 || query("WILL_DELETE") == 1 ) {
        return;
    }
    enemy->remove_killer(this_object());
    message_vision("$N臨死之前忽然發動了重生的制約，快速地衝向$n！\n\n", this_object(), enemy);

    if( sk < 80 ) raiseDamage = ob->query_stat_maximum("hp")/10;
    if( sk < 140 ) raiseDamage = ob->query_stat_maximum("hp")/9;
    if( sk < 200 ) raiseDamage = ob->query_stat_maximum("hp")/8;
    else raiseDamage = ob->query_stat_maximum("hp")/6;

    if( raiseDamage >= 2000 ) raiseDamage = 2000;

    this_object()->add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
    this_object()->add_temp("apply/attack", -raiseDamage);

    enemy->receive_damage(damage, this_object());
    message_vision("$N"HIW"七手八腳的把"NOR"$n"HIW"纏住，身體的中心開始發出"HIR+BLINK"紅色光芒"NOR+HIW"！\n"NOR, this_object(), enemy);
    message_vision( sprintf("$N盡了自己最後一分力量，將$n炸的四分五裂(%d) %s\n\n", damage, COMBAT_D->report_status(enemy)), this_object(), enemy);
    owner->delete_temp("TREE_ONE");
    owner->delete_temp("TREE_TWO");
    set("WILL_DELETE", 1);
    ::die();
    do_chat( ({ (: destruct, this_object() :) }) );
    return;
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