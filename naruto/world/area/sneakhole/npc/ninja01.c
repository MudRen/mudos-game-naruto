#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

int i = 0;

string *name1 = ({ "音舞", "聲宿", "律子", "絢華", "樂", "妙", "曲譜",
                   "奏鳴", "響", "漫音", "空悲" });

string *name2 = ({ "歌", "迷", "爍", "彩", "繞", "旋", "夢", "惑", "靡",
                   "飄搖", "獨享", "悠然", "平靜", "共鳴", "無畏",
                   "和合子", "好自在", "空無窮" });

void do_fight()
{
    int damage, raiseDamage, exact, evade;
    object enemy;
    string msg;

    enemy = this_object()->query_opponent();

    if( !enemy ) return;
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( i ) {
        case 0: msg = "\n$N"HIY"朝著"NOR"$n"HIY"射出一把飛針，針穿過洞穴的細風傳出鳴笛聲！\n";
                raiseDamage = 150;
                exact = COMBAT_D->exact(this_object(), enemy, 1)*1.5;
                evade = COMBAT_D->evade(enemy, this_object(), 1);
                break;
        case 1: msg = "\n$N"HIY"聽著刺中"NOR"$n"HIY"的風笛傳回微弱響聲，快速朝聲音處擲出鈴噹飛刀！\n";
                raiseDamage = 250;
                exact = COMBAT_D->exact(this_object(), enemy, 1)*1.25;
                evade = COMBAT_D->evade(enemy, this_object(), 1);
                break;
        case 2: msg = "\n$n"HIM"移動時使鈴鐺暗器發出聲響，"NOR"$N"HIM"聽聞後毫不考慮地朝音源擲出數把鋼針暗器！\n";
                raiseDamage = 500;
                exact = COMBAT_D->exact(this_object(), enemy, 1);
                evade = COMBAT_D->evade(enemy, this_object(), 1);
                break;
        default: msg = "\n$N"HIM"一時間找不到飛刀，居然把起髮夾射向$n！\n";
                 raiseDamage = 20;
                 exact = 0;
                 evade = 0;
                 break;
    }
    message_vision(msg+""NOR, this_object(), enemy);
    this_object()->damage_stat("mp", 5, this_object());
    if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
        add_temp("apply/attack", raiseDamage); 
        damage = COMBAT_D->isDamage(this_object(), enemy, 0);
        add_temp("apply/attack", -raiseDamage);

        if( damage < 50 ) damage = 35 + random(15);

        // 傷害盾吸收
        damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
        enemy->receive_damage(damage, this_object());
        message_vision( sprintf("$n被$N的暗器刺中，暗器立刻發出的聲響，讓$N再次發現$n的位置(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
        i++;
        if( i >= 2 ) i = 2;
    } else {
        message_vision("但是$n這次看準了攻擊，飛快的從一旁閃了開來。\n\n", this_object(), enemy);
        i = 0;
    }
    return;
}
void create()
{
    set_name( name1[random(sizeof(name1))] + name2[random(sizeof(name2))], ({ "ninja" }));
    set_race("human");
    set_level(28+random(3));
    set("gender", "female");
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
        (: command, "say 小看我會讓你後悔的！" :),
        (: do_fight :),
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