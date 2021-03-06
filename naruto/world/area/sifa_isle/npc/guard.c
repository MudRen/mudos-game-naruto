#include <ansi.h>
#include <npc.h>

inherit F_SEASOLDIER;

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
    exact = COMBAT_D->exact(this_object(), enemy, 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    message_vision("\n$N用火砲對準$n，轟隆一聲發射出去，$N整個人跌了一跤。\n", this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("結果火砲打中了地面，地上一片焦黑。\n\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    raiseDamage = 150;

    add_temp("apply/attack", raiseDamage); 
    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/twohanded"));
    add_temp("apply/attack", -raiseDamage);

    if( damage < 50 ) damage = 40 + random(10);

    enemy->damage_stat("hp", damage, this_object());
    message_vision( sprintf("$n「磅」地一聲，火彈在$n的身上炸開，受到嚴重的傷害(%d) %s\n\n"NOR, damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
    return;
}
void create()
{
    set_name("海軍士官", ({ "guard" }) );
    set_race("human");
    set_level(28);
    set("title",HIC"司法島"NOR);
    set("gender", "male");
    set("class", "guard_sea");
    set("camp", "police");
    set("age", 10+random(71));
    set("long", "手持重型火器的高級海軍人員，專門負責守門。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":30+random(171), "p1":60, "p2":100 ]),  // 銀子
        ([ "type":"obj", "id":102, "amount":1, "p1":30, "p2":100 ]),              // 火繩
        ([ "type":"wp", "id":58, "amount":1, "p1":1, "p2":200 ]),                 // 海軍制式火炮
        ([ "type":"eq", "id":98, "amount":1, "p1":1, "p2":150 ]),                 // 海軍西裝上衣
        ([ "type":"eq", "id":96, "amount":1, "p1":1, "p2":300 ]),                 // 海軍西裝長褲
        ([ "type":"obj", "id":106, "amount":1, "p1":1, "p2":800 ]),               // 白雲飛天滑板
    }) );
    setup();
    carry_object(_DIR_AREA_"sifa_isle/npc/wp/fire.c")->wield("twohanded");
}