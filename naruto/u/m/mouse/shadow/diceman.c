#include <npc.h>
#include <ansi.h>

void do_clone()
{
    object enemy, item;
    // 沒有敵人
    enemy = this_object()->query_opponent();
    item = new(__DIR__"item/r_dice.c");
    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    if( this_object()->query_temp("quest/psychical") == 1) {
    return;
    }
    this_object()->add_temp("quest/psychical", 1);
    message_vision("$N聚集身上念力，慢慢具現化出一顆"HIW"風險骰子"NOR"！\n", this_object(), enemy);
    item->move(this_object());
    call_out("rolldice_1",5,this_object(),enemy);
    return;
}
void rolldice_1()
{
    int damage;
    object enemy;
    enemy = this_object()->query_opponent();
    // 沒有敵人
    this_object()->delete_temp("quest/psychical");
    if( !enemy ) {
        do_chat(({ 
            (: command, "drop dice" :),
        }));
        return;
    }
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy)) {
            do_chat(({ 
                (: command, "drop dice" :),
            }));
            return;
        }
    } else {
        if( environment(enemy) != environment(this_object()) ) {
            do_chat(({ 
                (: command, "drop dice" :),
            }));
            return;
        }
    }
    do_chat(({ 
        (: command, "roll dice" :),
    }));
    return;
}
void create()
{
    set_name("骰男", ({ "dice man", "man" }));
    set_race("human");
    set_level(35);
    set("title",HIW"玩骰高手"NOR);
    set("age", 20);
    set("long", "玩骰狂人，連身上衣服都是骰子點數。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
       (: command, "say 有興趣玩一把嗎？" :),
       CYN"骰男從懷中拿出骰子把玩著。\n"NOR,
       CYN"骰男將骰子朝地上一丟，結果是個"HIY"大吉"NOR+CYN"。\n"NOR,
    }) );
    // 戰鬥動作
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: do_clone :),
        (: command, "grin" :),
    }) );
    setup();
    set_stat_current("hp", 9999);             // 體力
    set_stat_maximum("hp", 9999);             // 最大值
}
int give_check(object ob)
{
    if( ob->id("_BANDIT_CARD_") ) return 1;           // 殺手雇用卡
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say 忙線中阿！" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 沒看到我在打架嗎！" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( ob->query_amount() > 1 ) {
                do_chat((: command, "say 只要給我一張就夠了。" :));
                return 0;
            }
            message_vision("$N冷笑著說道﹕"HIG"找我就找對人了！\n"NOR, this_object());
            do_chat(({ 
               (: command, "follow " + this_player()->query("id") :),
               (: command, "guard " + this_player()->query("id") :),
               ( : destruct , ob : )
            }));
            break;
        default:
            do_chat((: command, "say 我不需要這樣東西。" :));
            return 0;
            break;
    }
    return 1;
}
void die()
{
    object ob, *obs;
    obs = all_inventory(this_object());
    if( this_object()->query_temp("quest/psychical") == 1 ||
        this_object()->query_temp("quest/rolldice") == 1) {

        message_vision("因為$N死掉所以"HIW"風險骰子"NOR"漸漸消失了...。\n"NOR, this_object());
        this_object()->delete_temp("quest/psychical");
        foreach( ob in obs ) destruct(ob);
    }
    ::die();
}
