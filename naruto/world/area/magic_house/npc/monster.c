#include <ansi.h>
#include <npc.h>

void do_exit()
{
    mapping ward, war_data;
    string file, war;
    object room, *inv;
    int ntar;

    file = "/world/area/magic_house/house.c";
    room = load_object(file);
    inv = all_inventory(room);
    ward = WAR_D->getController();
    delete_temp("close_war");

    if( random(100) == 50 ) {
        foreach(war, war_data in ward) {
            if( war == "/world/war/magic_house.c" && war_data["start"] != 0 ) {
                // 找不到玩家就可以把 war 關了
                for(ntar=0;ntar<sizeof(inv);ntar++) {
                    if( userp(inv[ntar]) ) {
                        set_temp("close_war", 1);
                        break;
                    }
                    if( inv[ntar]->query("sktree") ) continue;
                }
                if( !query_temp("close_war") ) WAR_D->doEndWar(this_object(), "/world/war/magic_house.c");
            }
        }
    }
    if( environment(this_object())->query("MONSTER_WAR") == 1 ) {
        do_chat((: random_move :));
    } else {
        message_vision("$N被趕來的小丑抓回籠子裡去了...\n"NOR, this_object());
        destruct(this_object());
    }
    return;
}
void create()
{
    set_name("馬戲團野獸", ({ "monster" }));
    set_level(28+random(6));
    set_race("beast");
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("set_drop", ({
        ([ "type":"food", "id":15, "amount":1, "p1":10, "p2":100 ]), // 精力丸
        ([ "type":"food", "id":17, "amount":1, "p1":10, "p2":100 ]), // 體力丸
        ([ "type":"food", "id":19, "amount":1, "p1":10, "p2":100 ]), // 魔力丸
        ([ "type":"eq", "id":108, "amount":1, "p1":1, "p2":400 ]),   // 魔術項圈
    }) );
    // 隨機移動
    set("chat_chance", 10);
    set("chat_msg", ({
        (: do_exit :),
    }));
    set("sktree", random(5)+1);

    setup();
    switch( query("sktree") ) {
        case 1:
            set_name(HIW"羊雞"NOR, ({ "sheep chicken", "sheep", "chicken" }));
            set("limbs", ({ "羊頭", "身體", "腹部", "雞腿", "尾巴", "羊角", "雞冠" }) );
            set("long", "又像羊又像雞的奇怪生物，脾氣十分火爆。\n");
            break;
        case 2:
            set_name(HIC"晶鸚"NOR, ({ "kea" }));
            set("limbs", ({ "頭部", "身體", "腹部", "腳爪", "尾巴", "翅膀" }) );
            set("long", "被陽光照射時閃耀著有如水晶般亮光的鸚鵡。\n");
            break;
        case 3:
            set_name(HIR"稻麒"NOR, ({ "kilin" }));
            set("limbs", ({ "龍頭", "身體", "腹部", "馬蹄", "豹尾", "紅冠" }) );
            set("long", "全身火紅色的猛獸，因為喜食稻米又狀似神獸麒麟而得名。\n");
            break;
        case 4:
            set_name(HIB"嵐鳥"NOR, ({ "wind bird", "bird" }));
            set("limbs", ({ "頭部", "身體", "腹部", "腳爪", "尾巴", "翅膀" }) );
            set("long", "生長在山嵐之上的藍色大鳥，性格兇猛具有強烈攻擊性。\n");
            break;
        case 5:
            set_name(HIK"蛹室"NOR, ({ "pupa" }));
            set("limbs", ({ "蛹殼", "蛹壁", "蛹汁", "蛹根", "蛹莖", "觸手" }) );
            set("long", "某種生物的蛹，因為躲避天敵而逐漸進化成蛹也可以移動。\n");
            break;
    }
    // 增強
    add_temp("apply/attack", 60);
    add_temp("apply/armor", 30);
    add_temp("apply/exact", 10);
    add_temp("apply/evade", 10);
    add_temp("apply/intimidate", 5);
    add_temp("apply/wittiness", 5);
    add_temp("apply/int", 5);
    add_temp("apply/con", 5);
    add_temp("apply/str", 5);
    add_temp("apply/dex", 5);
}
void init()
{
    string msg;
    int i;
    object *inv;
    inv = all_inventory(environment(this_object()));

    /* 若 this_player() 看不見這個人物，則不引發戰鬥。 */
    if( !this_object()->visible(this_player()) ) return;

    /* 增加area判斷 add by -Acme- */
    if( environment()->is_area() && !area_environment(this_object(), this_player())) return;

    // 非玩家不用主動攻擊
    if( !userp(this_player()) ) return;

    switch( random(3) ) {
        case 0: msg = ""HIR"$N"HIR"兇性大發，一看到$n立刻撲了上來！"NOR"\n\n"; break;
        case 1: msg = ""HIR"$N"HIR"怪叫一聲張牙舞爪的撲上前來！"NOR"\n\n"; break;
        case 2: msg = ""HIR"$N"HIR"低聲吼叫猛地一個衝刺撲向$n！"NOR"\n\n"; break;
    }
    for(i=0;i<sizeof(inv);i++) {
        if( inv[i] == this_object() ) continue;
        if( !userp(inv[i]) ) continue;
        if( !this_object()->visible(inv[i]) ) continue;
        if( environment()->is_area() && !area_environment(this_object(), inv[i])) continue;
        if( this_object()->is_fighting(inv[i]) ) continue;
        if( living(inv[i]) ) {
            if( inv[i]->is_corpse() ) continue;

            // 若雙方正互相仇視中，開始戰鬥。
            if( inv[i]->is_killing(query("id")) ) {
                COMBAT_D->auto_fight(inv[i], this_object(), "hatred");
                continue;
            }
            if( is_killing(inv[i]->query("id")) ) {
                COMBAT_D->auto_fight(this_object(), inv[i], "hatred");
                continue;
            }
            // 在不仇視的情況下，等級不到 28 級就不攻擊
            if( inv[i]->query_level() < 28 ) continue;
            message_vision(msg, this_object(), inv[i]);
            this_object()->kill_ob(inv[i]);
            if( function_exists("accept_kill", inv[i]) && !inv[i]->is_killing(this_object()) && inv[i]->accept_kill(this_object()) ) continue;
            if( !inv[i]->is_killing(this_object()) ) inv[i]->kill_ob(this_object());
        }
    }
    return;
}
void die()
{
    string file;
    object enemy, room, *inv;
    int i, j, ntar;

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
    file = "/world/area/magic_house/house.c";
    room = load_object(file);
    inv = all_inventory(room);
    delete_temp("close_war");

    for(ntar=0;ntar<sizeof(inv);ntar++) {
        if( inv[ntar]->query("verbs") && inv[ntar]->query("sktree") ) {
            add_temp("close_war", 1);
            if( query_temp("close_war") > 2 ) break;
        } else continue;
    }
    // 掃完都沒發現動物就關 war
    if( query_temp("close_war") < 2 ) WAR_D->doEndWar(this_object(), "/world/war/magic_house.c");

    i = random(this_object()->query_level())*2 + 100;
    j = i*2 + random(500);

    if( enemy->query("bank") > 1000000 && enemy->query_point("learn") < 500000 ) {
        enemy->add("bank", -j);
        tell_object(enemy, HIY"\n因為殺死"NOR+this_object()->query("name")+HIY"馬戲團從你銀行裡拿走了"HIR"["+chinese_number(j)+"]"HIY"兩賠償金、額外獲得了"HIG"["HIC+chinese_number(i)+HIG"]"HIY"點學點。\n\n"NOR);
    } else if( enemy->query_point("learn") < 500000 ) {
        tell_object(enemy,HIY"\n因為殺死"NOR+this_object()->query("name")+HIY"你額外獲得了"HIG"["HIC+chinese_number(i)+HIG"]"HIY"點學點。\n\n"NOR);
    }
    enemy->add_point("learn", i);
    ::die();
    return;
}
