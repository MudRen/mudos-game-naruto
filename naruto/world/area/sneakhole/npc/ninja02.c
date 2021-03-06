#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

string *name1 = ({ "音舞", "聲宿", "律子", "絢華", "樂", "妙", "曲譜",
                   "奏鳴", "響", "漫音", "空悲" });

string *name2 = ({ "歌", "迷", "爍", "彩", "繞", "旋", "夢", "惑", "靡",
                   "飄搖", "獨享", "悠然", "平靜", "共鳴", "無畏",
                   "和合子", "好自在", "空無窮" });

void do_fight()
{
    int damage, raiseDamage, exact, evade;
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
    exact = COMBAT_D->intimidate(this_object(), 1);
    evade = COMBAT_D->wittiness(enemy, 1);

    this_object()->damage_stat("mp", 10, this_object());
    message_vision("\n$N兩手快速伸出抓住$n兩肩，釋放大量查克拉『"HIC"響鳴穿"NOR"』！\n"NOR, this_object(), enemy);
    if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        message_vision("$n立刻將勁力集中在雙肩，運用巧勁將$N的攻擊反震了回去！\n\n", this_object(), enemy);
        this_object()->start_busy(2);
    } else {
        raiseDamage = 400;

        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, 0);
        add_temp("apply/attack", -raiseDamage);

        if( damage < 150 ) damage = 100 + random(50);

        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("大量查克拉灌入$n雙肩，震的$n肩部血管破裂，皮膚漸漸泛紫(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        enemy->start_busy(2);
    }
    return;
}
void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "ninja" }));
    set_race("human");
    set_level(28+random(3));
    set("gender", "male");
    set("nickname",HIM"音之忍者"NOR);
    set("age", 10+random(51));
    set("camp", "music");
    set("long", "音隱村的忍者，似乎正在這裡進行什麼工程。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight :),
        (: command, "say 為了大蛇丸大人而奮戰！" :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":5, "amount":1, "p1":12, "p2":100 ]),               // 苦無
        ([ "type":"obj", "id":29, "amount":50+random(100), "p1":80, "p2":100 ]),// 銀子
        ([ "type":"food", "id":51, "amount":1, "p1":7, "p2":100 ]),             // 燒賣
        ([ "type":"food", "id":10, "amount":1, "p1":6, "p2":100 ]),             // 豚骨
        ([ "type":"food", "id":11, "amount":1, "p1":2, "p2":100 ]),             // 正油
        ([ "type":"eq", "id":89, "amount":1, "p1":1, "p2":400 ]),               // 護腰
        ([ "type":"eq", "id":90, "amount":1, "p1":1, "p2":300 ]),               // 護額
    }) );
    setup();
    // 增強
    add_temp("apply/hp", 500);
    add_temp("apply/armor", 50);
    add_temp("apply/exact", 20);
    add_temp("apply/intimidate", 20);
    do_heal();
}