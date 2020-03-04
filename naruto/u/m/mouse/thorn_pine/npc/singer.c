#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;

void do_fight()
{
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
    if(enemy->is_busy()) {
        message_vision(CYN"$N唱著令人動聽的歌聲。\n"NOR, this_object(), enemy);
        return;
    }
    message_vision("$N唱出美妙的歌聲企圖迷惑$n！\n"NOR, this_object(), enemy);
    if( random(enemy->query_ability("intimidate")) > 100) {
        message_vision("        $n沒有被這陣聲音所迷惑。\n", this_object(), enemy);
        this_object()->start_busy(1);
        return;
    }
    message_vision("        $n被聲音所惑！魂不知飛哪去了。\n", this_object(), enemy);
    enemy->start_busy(2);
    return;
}
void create()
{
    set_name("豹歌手", ({ "bow singer", "singer" }));
    set_race("human");
    set_level(35);
    set("gender", "female");
    set("age", 20+random(51));
    set("limbs", ({ "頭部", "身體", "腹部", "腿部", "尾巴", "耳朵", "肩部", "背部" }));
    set("long", "豹族人歌手，平常負責唱歌、跳舞與安撫人心。\n");
    set("chat_chance", 5);
    set("chat_msg", ({
        CYN"豹歌手美妙的歌聲讓四周豹人拍手叫好。\n"NOR,
        CYN"豹歌手高聲的唱著歌曲。\n"NOR,
    }));
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: do_fight :),
    }) );
    set("set_drop", ({
        ([ "type":"wp", "id":33, "amount":1, "p1":15, "p2":100 ]),  // 大木棒
        ([ "type":"wp", "id":34, "amount":1, "p1":5, "p2":100 ]),   // 鐵刀
        ([ "type":"wp", "id":43, "amount":1, "p1":1, "p2":100 ]),   // 刺木槍
        ([ "type":"wp", "id":36, "amount":1, "p1":1, "p2":150 ]),   // 刻紋劍
    }) );
    setup();
}
int accept_fight(object ob)
{
    if( this_player()->query_temp("quest/villpk") < 1) {
        do_chat(({
           (: command, "sorry" :),
           (: command, "say 族長有令，平時一律不準打架" :),
        }));
        return 0;
    }
    return ::accept_fight(ob);
}
