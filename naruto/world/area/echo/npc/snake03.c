#include <npc.h>
#include <ansi.h>

inherit F_SOLDIER;

void create()
{
    if( random(2) == 1) {
        set_name("蛇人", ({ "snake man", "man" }) );
        set("gender", "male");
    } else {
        set_name("蛇女", ({ "snake woman", "woman" }) );
        set("gender", "female");
    }
    set_level(24+random(2));
    set_race("human");
    set("age", 10+random(51));
    set("limbs", ({ "蛇頭", "蛇尾", "腹部", "胸口", "腳部", "肩膀", "腰部" }) );
    set("title",HIG"神廟遺族"NOR);
    set("long", "外表如同蛇般，卻用兩隻腳走路的蛇人，似乎住在這裡。\n");
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        (: command, "say 可惡的人類！" :),
        (: command, "say 蛇族才是最偉大的種族！" :),
    }) );
    set("set_drop", ({
        ([ "type":"eq", "id":87, "amount":1, "p1":1, "p2":400 ]),     // 蛇神項鍊
        ([ "type":"food", "id":29, "amount":1, "p1":25, "p2":100 ]),  // 蛇蛋
        ([ "type":"food", "id":30, "amount":1, "p1":15, "p2":100 ]),  // 蛇膽
        ([ "type":"obj", "id":24, "amount":1, "p1":15, "p2":100 ]),   // 蛇皮
        ([ "type":"wp", "id":14, "amount":1, "p1":10, "p2":100 ]),    // 蛇牙
          ([ "type":"obj", "id":88, "amount":1, "p1":1, "p2":800 ]),  // 起司飛天掃帚
    }) );
    setup();
}
void init()
{
    int i;
    object *inv;
    inv = all_inventory(environment(this_object()));

    /* 若 this_player() 看不見這個人物，則不引發戰鬥。 */
    if( !this_object()->visible(this_player()) ) return;

    /* 增加area判斷 add by -Acme- */
    if( environment()->is_area() && !area_environment(this_object(), this_player())) return;

    // 看到老張女兒便開打
    if( this_player()->id("_HELP_GIRL_") && !this_player()->is_fighting(this_player()) ) {
        message_vision(HIR"$N一見到$n便大聲喊著：「活祭品跑了！快去抓回來！」\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
    /* 非玩家不用判斷 */
    if( !userp(this_player()) ) return;

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
            switch( query("attitude") ) {
                case "aggressive":
                /* 主動攻擊的生物 */
                COMBAT_D->auto_fight(this_object(), inv[i], "aggressive");
                break;
            }
        }
    }
}
