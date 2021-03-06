#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "sad" :),
        (: command, "say 身為人類救星卻淪落到這個下場！" :),
        (: command, "draw" :),
    }) );
}
void create()
{
    set_name("失敗的麵", ({ "spiderman" }));
    set_race("human");
    set_level(50);
    set("title",HIR"人類救星"NOR);
    set("long", "穿著一身奇怪服裝的人，正蹲在角落裡畫圈圈...\n");
    set("age", 22);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
        (: command, "draw" :),
    }) );
    setup();
}
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "蜘蛛皇后" ) {
        do_chat( ({
           (: command, "say 上次遇到牠是躲在絲橋的附近。" :),
           (: command, "say 不知道有沒有換位置..." :),
        }) );
        return 1;
    }
    if( arg == "人類救星" ) {
        do_chat( ({
           (: command, "sigh" :),
           (: command, "say 說來就是我有次不小心被蜘蛛皇后給咬到了。" :),
           (: command, "say 結果隔天醒來身體變壯了..." :),
           (: command, "say ...還換來了一種會噴蜘蛛絲的能力。" :),
           (: command, "say 後來我善用了這種力量，為了人類而奮戰！" :),
           (: command, "sad" :),
           (: command, "say 可惜我不是蜘蛛，一天能製造的蜘蛛絲已經不夠我消耗了。" :),
           (: command, "say 想來這裡殺蜘蛛拿他們的絲去用，卻下不了手。" :),
           (: command, "cry" :),
           (: command, "say 誰能幫忙我阿∼！" :),
           (: command, "draw" :),
        }) );
        return 1;
    }
    if( arg == "幫忙" || arg == "幫你" ) {
        if( this_player()->query_level() < 10 ) {
            message_vision("$N似乎不太想理$n\n", this_object(), this_player());
            return 0;
        }
        if( this_player()->query_temp("quest/spiderman") == 1) {
            do_chat( ({
               (: command, "hold "+this_player()->query("id") :),
               (: command, "say 太感謝你了！" :),
            }) );
        } else {
            do_chat( ({
               (: command, "wa" :),
               (: command, "say 那就麻煩你了！" :),
               (: command, "say 只要給我十個蜘蛛黏液就可以了！" :),
            }) );
        this_player()->add_temp("quest/spiderman", 1);
        }
        return 1;
    }
    return 1;
}

int give_check(object ob)
{
    if( ob->id("_SPIDER_MUCUS_") ) return 1;    // 蜘蛛黏液
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;

    if( is_busy() ) {
        do_chat((: command, "say Wait！Wait Me！" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 正在戰鬥！等我一下吧！" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( this_player()->query_temp("quest/spiderman") < 1 ) {
                do_chat((: command, "say 雖然很想拿...不過我沒請你幫忙。" :));
                return 0;
            }
            if( ob->query_amount() != 10 ) {
                do_chat((: command, "say 一次十個就好！太多太少你我都吃虧。" :));
                return 0;
            }
            message_vision("$N接過$n高興的大叫﹕"HIG"Oh Ya！\n"NOR, this_object(), ob);
            do_chat( ({
               (: command, "say 太感謝你了！全人類都以你為榮！" :),
               (: command, "spank " + this_player()->query("id") :),
               (: command, "say 這 "HIY"6000"HIG" 兩銀子就不客氣的收下吧！"NOR :),
               ( : destruct , ob : ),
            }) );
            tell_object(me, "( "HIY+6000+HIG" 兩銀子已經自動存在銀行裡。"NOR")\n");

            me->add("bank", 6000);

            // 移除暫存的資料
            me->delete_temp("quest/spiderman");
            break;
        default:
            do_chat((: command, "say 真是對不起，我只要蜘蛛黏液。" :));
            return 0;
            break;
    }
    return 1;
}
