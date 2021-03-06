#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("山狼", ({ "hill wolf", "wolf" }) );
    set_race("beast");
    set_level(15);
    set("age", 11+random(21));
    set("long", "一隻看起來很兇狠的山狼，時常對天狂哮。\n");
    set("limbs", ({ "狼頭", "身體", "腹部", "狼腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        CYN"山狼向天狂哮著「ㄠ∼ㄨ∼ㄠ∼ㄨ∼」\n"NOR,
    }) );
    set("set_drop", ({
        ([ "type":"obj", "id":79, "amount":1, "p1":15, "p2":100 ]),    // 狼牙
        ([ "type":"food", "id":32, "amount":1, "p1":80, "p2":100 ]),   // 狼心
        ([ "type":"food", "id":33, "amount":1, "p1":80, "p2":100 ]),   // 狼肺
        ([ "type":"eq", "id":57, "amount":1, "p1":20, "p2":100 ]),     // 狼腳
        ([ "type":"eq", "id":58, "amount":1, "p1":18, "p2":100 ]),     // 狼皮
        ([ "type":"eq", "id":59, "amount":1, "p1":20, "p2":100 ]),     // 狼腳
        ([ "type":"eq", "id":60, "amount":1, "p1":20, "p2":100 ]),     // 狼頭
        ([ "type":"eq", "id":61, "amount":1, "p1":25, "p2":100 ]),     // 狼尾
        ([ "type":"wp", "id":13, "amount":1, "p1":10, "p2":100 ]),     // 狼爪
    }) );
    setup();
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
        message_vision(HIR"$N狂哮一聲，開始攻擊$n了！\n\n"NOR, this_object(), this_player());
        this_object()->kill_ob(this_player());
    }
}
