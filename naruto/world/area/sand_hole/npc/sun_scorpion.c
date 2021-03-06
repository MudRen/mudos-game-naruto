#include <npc.h>
#include <ansi.h>

void do_fight()
{
    int damage, i, raiseDamage, exact, evade;
    object enemy;
    object *targets;
    mapping cnd = ([]);

    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    exact = COMBAT_D->exact(this_object(), enemy, 1) + COMBAT_D->intimidate(this_object(), 1);

    if( enemy->query_condition("scorpion_poison") ) {
        message_vision("\n$N"YEL"身上的蠍殼漸漸發出比剛才還要耀眼的光芒，幾乎讓人無法直視...\n"NOR, this_object(), enemy);

        for(i=0;i<sizeof(targets);i++) {
            if( i > 3 ) break;   // 最多攻擊四人
            evade = COMBAT_D->evade(targets[i], this_object(), 1)*2;

            if( !COMBAT_D->SkillHit(this_object(), targets[i], exact, evade) ) {
                message_vision("一陣炙熱的「"HIR"太陽射線"NOR"」噴向$n，但是沒中...\n", this_object(), targets[i]);
            } else {
                damage = 800;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < 300 ) damage = 200 + random(100);

                targets[i]->receive_damage(damage, this_object());
                message_vision( sprintf("炙熱的「"HIR"太陽射線"NOR"」嗡地照在$n的身上，瞬間將$n燒成灰塵了(%d) %s\n", damage, COMBAT_D->report_status(targets[i])), this_object(), targets[i]);
            }
        }
        message_vision("\n", this_object());
        this_object()->start_busy(2);
    } else {
        message_vision("\n$N"HIM"將尾部對準$n，忽然爬了過來狠狠的一螫！\n"NOR, this_object(), enemy);
        if( random(500) < random(300) ) {
            message_vision("但是蠍尾只是刺中了$N的衣服，並沒有傷到$N。\n\n", enemy, this_object());
            this_object()->start_busy(1);
            return;
        }
        enemy->damage_stat("hp", damage, this_object());
        message_vision("$N唉呦一聲，蠍毒慢慢的流進$N的體內，使$N痛苦不堪。\n\n", enemy, this_object());
        enemy->start_busy(1);

        cnd["name"] = MAG+"蠍毒"+NOR;
        cnd["duration"] = 10;
        cnd["from"] = this_object();

        enemy->set_condition("scorpion_poison", cnd);
    }
    return;
}

void create()
{
    set_name(HIY"太陽之蠍"NOR, ({ "sun scorpion", "scorpion" }) );
    set_level(60);
    set_race("beast");
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("age", 5001);
    set("title",HIR"沉睡的遺蹟之主"NOR);
    set("limbs", ({ "蠍頭", "雙螯", "蠍尾", "肚子", "蠍足", "太陽鎧", "閃光" }) );
    set("long", "古代遺蹟中的守護者，因為遺蹟的損毀導致暫時處於休眠狀態，才會\n"
                "讓沙賊佔據了這裡。蠍子身上的蠍殼發出有如太陽般耀眼的光芒，但\n"
                "是雙螯卻又是讓人害怕的紫色，肯定非常之毒。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":110, "amount":1, "p1":1, "p2":100 ]),             // 毒蠍雙螯
        ([ "type":"eq", "id":112, "amount":1, "p1":5, "p2":100 ]),             // 古代頭盔
        ([ "type":"obj", "id":113, "amount":2+random(5), "p1":80, "p2":100 ]), // 毒蠍血清
    }) );
    setup();
    add_temp("apply/armor", 200);
    add_temp("apply/attack", 50);
}
void die()
{
    object enemy, killer;
    int i;
    string msg;

    enemy = this_object()->last_damage_giver();
    i = 2 + random(2);

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
    msg = "\n\n\t"+this_object()->query("name")+HIR"將殘存的生命化為烈日，瞬間將大地照耀成白夜\n\n"NOR;
    msg += HIR"\t\t只有"NOR+HIW+enemy->query("name")+NOR+HIR"沒被這光芒所照亮...\n\n\n"NOR;

    killer->add("exchange", i);
    CHANNEL_D->say_channels(this_object(), "news", msg, 1);
    tell_object(killer, HIY"(因為你殺死太陽之蠍獲得了 "+i+" 點兌換點數。)\n"NOR);
    ::die();
    return;
}