#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

string *name = ({ "小兔子", "小貓", "小狗", "小猴子", "小雞",
                  "小綿羊", "小豬", "小鴨", "小河馬", "小牛",
                  "小駱駝", "小馬", "小熊", "小企鵝", "小狼", });

void do_fight()
{
    mapping cnd = ([]);
    int damage, raiseDamage, i, exact, evade;
    object enemy, target;
    object *inv;
    inv = all_inventory(environment(this_object()));

    // 沒有敵人
    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( !inv ) return;
    if( !this_object() ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    // 先找有沒有非玩家的屍體
    for(i=0;i<sizeof(inv);i++) {
        if( inv[i] == this_object() ) continue;
        if( !this_object()->visible(inv[i]) ) continue;
        if( environment()->is_area() && !area_environment(this_object(), inv[i])) continue;
        if( inv[i]->query("userp") == 0 && inv[i]->is_corpse() ) {
            target = inv[i];
            break;
        }
    }

    cnd["name"] = HIG"中毒"NOR;
    cnd["duration"] = 10;

    if( !target ) {
        damage = 100 + random(150);
        this_object()->damage_stat("mp", 10, this_object());
        if( !COMBAT_D->isHit(this_object(), enemy) ) {
            message_vision("$N左手發出一陣"HIG"綠色閃光"NOR"，但是什麼事也沒發生。\n", this_object());
        } else {
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("$N伸出左手觸碰$n的身體，$n只感覺一股"HIG"令人噁心的念"NOR"傳入自己體內(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->set_condition("vp", cnd);
        }
        return;
    }
    exact = this_object()->query_level();

    this_object()->damage_stat("mp", 30, this_object());
    message_vision(CYN"\n$N邪惡地微笑，伸出左手貼在"NOR+target->query("name")+CYN"的腹部，慢慢將念力灌進"NOR+target->query("name")+CYN"...\n\n"NOR, this_object(), enemy);
    message_vision(target->query("name")+GRN"瞬間膨脹起來，發出噁心的屍臭，忽然爆裂開來，噴出充滿腐蝕的屍毒！\n"NOR, this_object(), enemy);
    for(i=0;i<sizeof(inv);i++) {
        if( inv[i] == this_object() ) continue;
        if( !this_object()->visible(inv[i]) ) continue;
        if( environment()->is_area() && !area_environment(this_object(), inv[i])) continue;
        if( living(inv[i]) ) {
            if( inv[i]->is_corpse() ) continue;

            evade = inv[i]->query_level();
            raiseDamage = target->query("level")*20 + 100 + random(200);

            if( COMBAT_D->SkillHit(this_object(), inv[i], exact, evade) ) {
                if( inv[i]->query("camp") != "hole_bandit" ) {

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(inv[i], enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 300 ) damage = 150 + random(150);

                    inv[i]->receive_damage(damage, this_object());
                    message_vision( sprintf(HIG"劇毒噴濺在$N的身上，造成嚴重的灼傷與中毒(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(inv[i]) ), this_object(), inv[i]);
                    inv[i]->set_condition("vp", cnd);
                } else {
                    message_vision(HIG"$N雖然早知道攻擊方式，卻仍然吸入了幾口毒氣...\n"NOR, inv[i]);
                    inv[i]->set_condition("vp", cnd);
                }
            } else {
                message_vision("但是$N的運氣不錯，屍毒沒有噴濺在$N的四周。\n", inv[i]);
            }
        }
    }
    destruct(target);
    message_vision("\n"NOR, this_object());
    return;
}

void do_heal()
{
    string animal;
    int damage;
    object item;

    // 已經有召過屍體就暫時不召了, hp滿的也不召
    if( present("_ANIMAL_CORPSE_", environment(this_object())) ) return;
    if( query_stat("hp") >= query_stat_maximum("hp") ) return;

    animal = name[random(sizeof(name))];
    item = new("/obj/corpse.c");
    item->set_name(animal+"的乾屍", ({ "corpse", "_ANIMAL_CORPSE_" }) );
    item->set("long", "曾經是一隻可愛又活潑的小動物，但現在只是一具乾枯屍體了。\n");
    item->set("level", 15);
    item->set("no_sac", 1);

    message_vision("\n$N"HIM"難過地按著自己的傷口，忽然從斗篷裡拿出一隻十分可愛的"+animal+"...\n"NOR, this_object());

    if( environment(this_object())->is_area() ) move_side(item, this_object());
    else item->move(environment(this_object()));

    this_object()->heal_stat("hp", query_stat_maximum("hp")/2);
    if( query_stat("hp") > query_stat_maximum("hp") ) set_stat_current("hp", query_stat_maximum("hp"));
    message_vision(HIG"$N居然狠心的伸出右手貼在"NOR+animal+HIG"頭頂，手掌發出一團綠色毒氣將"NOR+animal+HIG"的鮮血導入自己體內\n"NOR, this_object());
    message_vision(HIG"只見$N的傷口慢慢癒合，卻吸乾了"NOR+animal+HIG"的生命力，$N便將如同乾屍的"NOR+animal+HIG"丟在地上。\n\n"NOR, this_object());
    return;
}

void create()
{
    set_name("魔高", ({ "mo gao", "gao" }));
    set_class("middle");
    set_level(45);
    set("title", "賊之首");
    set("long", "高約一丈的人，身上覆蓋著深綠色的斗篷，看起來有些奇特，他就是\n"
                "使用特殊技巧幫助盜賊們擊退忍者和獵人的高手，仔細看他的身上籠\n"
                "罩著一層綠色光芒，這層光芒時亮時暗，還散發著獨特的臭味。聞到\n"
                "的人似乎都會感覺腦袋有陣暈眩，不過隔一下子就恢復正常了。\n");
    set("camp", "hole_bandit");
    set("set_drop", ({
        ([ "type":"obj", "id":28, "amount":2+random(2), "p1":50, "p2":100 ]), // 黃金
        ([ "type":"obj", "id":22, "amount":1, "p1":20, "p2":100 ]),           // 黃金牙
        ([ "type":"wp", "id":16, "amount":1, "p1":1, "p2":200 ]),             // 高原劍
        ([ "type":"wp", "id":70, "amount":1, "p1":1, "p2":500 ]),             // 山峰劍
        ([ "type":"eq", "id":66, "amount":1, "p1":50, "p2":100 ]),            // 盜道鞋
        ([ "type":"eq", "id":67, "amount":1, "p1":50, "p2":100 ]),            // 青銅護腕
    }) );
    // 隨機移動
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: do_heal :),
    }) );
    setup();

    // 增強
    add_temp("apply/attack", 100);
    add_temp("apply/armor", 60);
    add_temp("apply/exact", 20);
    add_temp("apply/evade", 20);
    add_temp("apply/intimidate", 10);
    add_temp("apply/wittiness", 10);
    add_temp("apply/int", 7);
    add_temp("apply/con", 7);
    add_temp("apply/str", 7);
    add_temp("apply/dex", 7);
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
    msg = "\n\n"GRN+this_object()->query("name")+"的深綠斗篷中忽然噴出大量的綠氣！外表逐漸糢糊...\n\n"NOR+this_object()->query("name")+"："HIG"哈哈哈！可惡的"+enemy->query("name")+"！不過我"+this_object()->query("name")+"是不滅的！"NOR"\n\n"HIY+enemy->query("name")+HIY"殺死了四處姦淫擄掠的秘穴盜賊頭子"+this_object()->query("name")+"！附近居民歡聲雷動！\n\n\n"NOR;

    killer->add("exchange", 1);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死"+this_object()->query("name")+"獲得了 1 點兌換點數。)\n"NOR);
    ::die();
    return;
}