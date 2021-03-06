#include <npc.h>
#include <ansi.h>

void do_fight()
{
    mapping cnd = ([]);
    int damage;
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
    if( this_object()->query_condition("elf", 1) == 0) {
        message_vision("\n$N拿出一個裝有藍色液體的針筒「"BBLU+HIW"腦內麻藥"NOR"」噗的一聲刺在自己身上！\n"NOR,this_object(), enemy);
        message_vision("過沒多久$N腳步變的更加快速，迴避能力似乎提升了不少。\n\n"NOR,this_object(), enemy);

        cnd["name"] = HIB"腦內麻藥"NOR;
        cnd["duration"] = 100;
        cnd["evade"] = 50;

        this_object()->set_condition("elf", cnd);
    } else {
        message_vision("\n$N反手握住手術刀，忽然身子整個一沉雙膝跪地，一式「"HIW"猛虎落地式"NOR"」！\n"NOR,this_object(), enemy);
        if( !COMBAT_D->isHit(this_object(), enemy) ) {
            message_vision("忽然$n四面的地上「碰」地一聲爆出數根鋼針，差點刺傷了$n。\n\n"NOR, this_object(), enemy);
            this_object()->start_busy(1);
        } else {
            damage = COMBAT_D->isDamage(this_object(), enemy, this_object()->query_temp("weapon/righthand"));
            if( damage < 350 ) {
                damage = 250 + random(100);
            } else {
                damage += 350;
            }
            enemy->damage_stat("hp", damage, this_object());
            message_vision( sprintf("正當$n傻眼之時，地面「碰」地一聲爆出數根鋼針，不偏不倚的刺進$n的全身造成創傷(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
        }
    }
    return;
}
void do_heal()
{
    if( query_stat("hp") < 3000 ) {
        message_vision("$N"HIW"拿出手術刀對自己使用外科手術，身上的傷口快速回復了。\n", this_object());
        set_stat_current("hp", query_stat_maximum("hp"));
        set_stat_current("ap", query_stat_maximum("hp"));
        set_stat_current("mp", query_stat_maximum("hp"));
    }
    return;
}
void create()
{
    set_name("虎力爽", ({ "hu li song", "hu", "song" }) );
    set_level(45);
    set_race("human");
    set("age", 42);
    set("title",YEL"沙穴副首"NOR);

    set("nickname",HIW"虎弟"NOR);
    set("camp", "sand_bandit");
    set("long", "頭髮染成一片白色，兩手拿著金閃閃的手術刀，右眼一道由頭頂劃到\n"
                "臉頰的刀疤看起來十分恐怖，像極了哪裡的傭醫。\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: do_heal :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":49, "amount":1, "p1":6, "p2":100 ]),       // 彎刀
        ([ "type":"wp", "id":27, "amount":1, "p1":1, "p2":100 ]),       // 手術刀
        ([ "type":"wp", "id":29, "amount":1, "p1":1, "p2":1200 ]),      // 白虎
        ([ "type":"eq", "id":29, "amount":1, "p1":60, "p2":100 ]),      // 紅色羽毛頭巾
        ([ "type":"eq", "id":27, "amount":1, "p1":80, "p2":100 ]),      // 羽毛帽
    }) );
    setup();
    carry_object("/world/wp/scalpel.c")->wield("righthand");
}
void die()
{
    object enemy, killer;
    string msg;

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
    // 寵物殺死算主人的
    if( !userp(enemy) && objectp(enemy->query_owner()) ) {
        killer = enemy->query_owner();
    } else {
        killer = enemy;
    }
    msg = "\n\n"HIW+this_object()->query("name")+"說道：大哥！沙穴的兄弟們！再見了！\n"NOR;
    msg += HIR"\n"HIR"【社會新聞】"+this_object()->query("name")+"("+this_object()->query("id")+")死於"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")之手了！\n\n"NOR;

    killer->add("exchange", 1);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死虎力爽獲得了 1 點兌換點數。)\n"NOR);
    ::die();
    return;
}