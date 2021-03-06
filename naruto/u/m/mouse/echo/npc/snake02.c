#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

string report_status(object ob)
{
    int ratio;
    if( !ob->query_stat_maximum("hp") ) return "\n";
    ratio = (int)ob->query_stat("hp")*100/(int)ob->query_stat_maximum("hp");
    if( ratio > 80 ) return HIK"["HIG"$n" + HIG + ratio + "%" + HIK"]\n"NOR;
    else if( ratio > 30 ) return HIK"["HIY"$n" + HIY + ratio + "%" + HIK"]\n"NOR;
    else return HIK"["HIR"$n" + HIR + ratio + "%" + HIK"]\n"NOR;
}
void do_fight()
{
    int damage, i;
    object enemy;
    string msg;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    i = random(2);
    if( i == 0 ) {
        message_vision("$N"HIR"拿起木杖隨手一揮，快速打出火彈朝"NOR"$n"HIR"擲來！\n"NOR, this_object(), enemy);
        if( random(this_object()->query_ability("attack")) > random(enemy->query_ability("defend")) ) {
            damage = 90;
        } else {
            damage = 1+random(90);
        }
        if( random(3) > 1) {
            message_vision("        但是火彈打偏了。(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(1);
            return;
        }
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        「轟隆」一聲，$n被燒成一位裸體的黑人。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        return;
    } else
    if( i == 1) {
        message_vision("$N"HIC"拿起木杖朝"NOR"$n"HIC"一指！發出兩道冰刺順著木杖方向戳去！\n"NOR, this_object(), enemy);
        if( random(this_object()->query_ability("attack")) > random(enemy->query_ability("defend")) ) {
            damage = 75;
        } else {
            damage = 1+random(75);
        }
        if( random(3) > 1) {
            message_vision("        但是冰刺飛到一半就溶化了。(0)"+report_status(enemy)+"", this_object(), enemy);
            this_object()->start_busy(1);
            return;
        }
        enemy->damage_stat("hp", damage, enemy);
        message_vision("        「框啷」一聲，冰刺戳的$n直發抖。("+damage+")"+report_status(enemy)+"", this_object(), enemy);
        enemy->start_busy(1);
        return;
    }
    message_vision("$N"HIW"拿起木杖揮了幾下，卻沒發生任何事。\n"NOR, this_object(), enemy);
    return;
}
void create()
{
    set_name("蛇祭", ({ "snake gi", "gi" }) );
    set_race("human");
    set("gender", "male");
    set_level(30);
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
    set("chat_chance_combat", 20);
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
    switch( query("attitude") ) {
        case "aggressive":
            /* 主動攻擊的生物 */
            COMBAT_D->auto_fight(this_object(), this_player(), "aggressive");
            break;
        case "peaceful":
        default:
            break;
    }

    // 看到老張女兒便開打
    if( this_player()->id("_HELP_GIRL_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N一見到$n便大聲喊著：「活祭品跑了！快去抓回來！」\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
