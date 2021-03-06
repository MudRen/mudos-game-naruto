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
    if( this_object()->query_condition("body_strength_cond", 1) == 0) {
        message_vision("\n$N拿出幾把鋼針，一口氣刺向自己手上的幾個穴道「"BRED+HIW"肌肉強化"NOR"」！\n"NOR,this_object(), enemy);
        message_vision("過沒多久$N的手臂肌肉爆漲，攻擊力大幅上升了。\n\n"NOR,this_object(), enemy);

        cnd["name"] = HIR"筋肉開發"NOR;
        cnd["duration"] = 100;
        cnd["attack"] =  66;
        cnd["armor"] =  40;

        this_object()->set_condition("body_strength_cond", cnd);
    } else {
        message_vision("\n$N將手術刀埋入沙地後使出「"GRN"飛龍升天式"NOR"」強力的念刀衝破沙地直衝$n！\n"NOR,this_object(), enemy);
        if( !COMBAT_D->isHit(this_object(), enemy) ) {
            message_vision("嘩啦一聲，念刀在沙牆上砍出了一個大坑，四周沙屑不斷滑落。\n\n"NOR, this_object(), enemy);
            this_object()->start_busy(1);
        } else {
            damage = COMBAT_D->isDamage(this_object(), enemy, this_object()->query_temp("weapon/righthand"));
            if( damage < 400 ) {
                damage = 300 + random(100);
            } else {
                damage += 400;
            }
            enemy->damage_stat("hp", damage, this_object());
            message_vision( sprintf("刷地一聲，念刀劈砍在$n的身上，噴灑出大量鮮血，但隨即被沙地所吸乾(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
        }
    }
    return;
}

void do_startWar()
{
    if( query_stat("hp") < 3000 ) {
        message_vision("$N"HIW"拿出手術刀對自己使用外科手術，身上的傷口快速回復了。\n", this_object());
        set_stat_current("hp", query_stat_maximum("hp"));
        set_stat_current("ap", query_stat_maximum("hp"));
        set_stat_current("mp", query_stat_maximum("hp"));
    } else if( query("war_qk") == 0 ) {
        if( WAR_D->doStartWar(this_object(), "/world/war/sand_hole.c") ) message_vision(CYN"$N將長刀插在地圖上！終於決定進攻路線了！\n"NOR, this_object());
        else message_vision(CYN"$N拿起手上的地圖看了看，似乎在找什麼地方似的。\n"NOR, this_object());
        this_object()->set("war_qk", 1);
        call_out("war_qk", 301, this_object());
    } else {
        do_chat((: command, "say 晚點再派沙賊出去搜括些錢財吧..." :));
    }
}

void war_qk()
{
    message_vision("$N甩甩頭想了一下說道："HIG"嗯...差不多是時候了。\n"NOR, this_object());
    this_object()->delete("war_qk");
    return;
}

void create()
{
    set_name("龍角散", ({ "lon jiao san", "lon", "san" }) );
    set("channel_id", "龍角散");
    set_level(48);
    set_race("human");
    set("age", 42);
    set("camp", "sand_bandit");
    set("title",YEL"沙穴首領"NOR);
    set("nickname",GRN"龍兄"NOR);
    set("long", "頭髮染成一片綠色，兩手拿著金閃閃的手術刀，身上的衣服是類似風\n"
                "衣的長袍黑衣，看起來就像是哪裡來的密醫。\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: do_startWar :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":49, "amount":1, "p1":10, "p2":100 ]),      // 彎刀
        ([ "type":"wp", "id":27, "amount":1, "p1":5, "p2":100 ]),       // 手術刀
        ([ "type":"wp", "id":28, "amount":1, "p1":1, "p2":1000 ]),      // 青龍
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
    msg = "\n\n"HIG+this_object()->query("name")+"說道：老弟！沙穴首領之位就交給你了！\n"NOR;
    msg += HIR"\n"HIR"【社會新聞】"+this_object()->query("name")+"("+this_object()->query("id")+")死於"+enemy->rank()+enemy->query("name")+"("+enemy->query("id")+")之手了！\n\n"NOR;

    killer->add("exchange", 1);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死龍角散獲得了 1 點兌換點數。)\n"NOR);
    ::die();
    return;
}