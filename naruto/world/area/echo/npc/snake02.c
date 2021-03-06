#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void do_fight()
{
    int damage, raiseDamage, exact, evade;
    object enemy;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( random(1000) ) {
        case 0..450:
            exact = this_object()->query_level();
            evade = enemy->query_level();

            this_object()->damage_stat("mp", 20, this_object());
            message_vision("\n$N"HIR"拿起木杖隨手一揮，快速打出火彈朝"NOR"$n"HIR"擲來！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("但是$N的技巧不夠熟練，射出的火彈飛到老遠去了。\n\n", this_object(), enemy);
                this_object()->start_busy(1);
                return;
            }
            raiseDamage = 250;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            if( damage < 70 ) damage = 50 + random(20);

            // 傷害盾吸收
            damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("「轟隆」一聲，只聽見$n一聲慘叫，一位裸體的黑人就誕生了(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            break;
        case 451..550:
            message_vision("$N忽然想起了古老的咒文，但是唸了一段之後又搖搖頭，似乎記錯了...\n"NOR, this_object(), enemy);
            break;
        case 551..999:
            exact = this_object()->query_level();
            evade = enemy->query_level();

            this_object()->damage_stat("mp", 15, this_object());
            message_vision("\n$N"HIC"拿起木杖朝"NOR"$n"HIC"一指！發出兩道冰刺順著木杖方向戳去！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("只見冰刺飛到一半卻忽然失去了力量，直接扎在地上。\n\n", this_object(), enemy);
                return;
            }
            raiseDamage = 100;

            add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(this_object(), enemy, 0);
            add_temp("apply/attack", -raiseDamage);

            // 傷害盾吸收
            damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
            enemy->receive_damage(damage, this_object());
            message_vision( sprintf("「框啷」一聲，冰刺戳在$n的身上，凍的$n直發抖(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            enemy->start_busy(1);
            break;
    }
    return;
}
void create()
{
    set_name("蛇祭", ({ "snake gi", "gi" }) );
    set_race("human");
    set("gender", "male");
    set_level(35);
    set("age", 45);
    set("limbs", ({ "蛇頭", "蛇尾", "腹部", "胸口", "腳部", "肩膀", "腰部" }) );
    set("title",HIG"蛇族祭師"NOR);
    set("long", "手持一根木杖的蛇人，正在神壇中央舉行神祭。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say 偉大的蛇神阿！請接受這次的活祭品吧！" :),
        (: command, "say 為了蛇族的榮耀！" :),
        (: command, "say 給予我們活著的希望！就算與族人分隔兩地。" :),
    }));
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":100 ]),     // 蛇神項鍊
        ([ "type":"wp", "id":51, "amount":1, "p1":1, "p2":200 ]),     // 蛇杖
        ([ "type":"food", "id":29, "amount":1, "p1":50, "p2":100 ]),  // 蛇蛋
        ([ "type":"food", "id":30, "amount":1, "p1":35, "p2":100 ]),  // 蛇膽
        ([ "type":"obj", "id":24, "amount":1, "p1":35, "p2":100 ]),   // 蛇皮
        ([ "type":"wp", "id":14, "amount":1, "p1":30, "p2":100 ]),    // 蛇牙
    }) );
    setup();
    carry_object("/world/area/thorn_pine/npc/wp/thorn_staff")->wield("twohanded");
}
void init()
{
    if( this_object() == this_player() ) return;

    // 若 this_player() 看不見這個人物，則不引發戰鬥。
    if( ! this_object()->visible(this_player()) ) return;

    // 區域設定
    if( environment()->is_area() && !area_environment(this_object(), this_player()) ) return;

    // 若雙方正互相仇視中，開始戰鬥。
    if( this_player()->is_killing(query("id")) ) {
        COMBAT_D->auto_fight(this_player(), this_object(), "hatred");
        return;
    }
    if( is_killing(this_player()->query("id")) )
    {
        COMBAT_D->auto_fight(this_object(), this_player(), "hatred");
        return;
    }
    // 看到老張女兒便開打
    if( this_player()->id("_HELP_GIRL_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N一見到$n便大聲喊著：「活祭品跑了！快去抓回來！」\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
