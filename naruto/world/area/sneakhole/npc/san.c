#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "say 數量還少了好多..." :),
        (: command, "say 真希望有人能幫幫我..." :),
    }) );
}
void create()
{
    set_name("音鮮", ({ "in san", "san" }));
    set_race("human");
    set_level(20);
    set("title",HIB"收帳人"NOR);
    set("long", "手拿著一本帳冊，不知道在計算什麼。\n");
    set("age", 22);
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
        (: command, "say 嗯...又算錯了 :(" :),
    }) );
    setup();
}
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "數量" ) {
        do_chat( ({
           (: command, "say 大蛇丸大人要我們在幾個月內清除蜘蛛開通密道。" :),
           (: command, "say 不過這群蜘蛛還真會生...怎麼打都殺不完。" :),
           (: command, "say 有沒有人能幫忙殺蜘蛛阿！∼∼" :),
        }) );
        return 1;
    }
    if( arg == "蜘蛛" ) {
        do_chat( ({
           (: command, "say 就是陰影洞穴裡的那些毒蜘蛛！" :),
           (: command, "say 牠們阻撓了我們音隱的木葉侵略計劃！" :),
           (: command, "ack" :),
           (: command, "say 不是不是！是要開闢新的練功地區啦∼哈哈哈。" :),
        }) );
        return 1;
    }
    if( arg == "木葉侵略計劃" ) {
        do_chat( ({
           (: command, "headshake" :),
           (: command, "say 你聽錯了，我沒講過這種東西。" :),
        }) );
        return 1;
    }
    if( arg == "幫忙" || arg == "幫你" ) {
        if( this_player()->query_temp("quest/spiderkill") == 1) {
            do_chat( ({
               (: command, "say 答應了就快點幫忙打吧！" :),
            }) );
        } else {
            do_chat( ({
               (: command, "nod" :),
               (: command, "say 只要給我50盒蜘蛛標本就可以了！" :),
               (: command, "say 交給你摟！" :),
               (: command, "say 獎勵是寫屁眼喔！" :),
            }) );
        this_player()->add_temp("quest/spiderkill", 1);
        }
        return 1;
    }
    return 1;
}

int give_check(object ob)
{
    if( ob->id("__SAMPLE__") ) return 1;    // 蜘蛛標本
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say 急什麼！等我清點一下！想魚目混珠喔！" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 快死啦！救命阿！" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 1:
            if( this_player()->query_temp("quest/spiderkill") < 1 ) {
                do_chat((: command, "say 沒事獻殷勤，非奸即盜。" :));
                return 0;
            }
            if( ob->query_amount() != 50 ) {
                do_chat((: command, "say 只要給我五十盒就好。" :));
                return 0;
            }
            if( file_size("/world/book/know1.c") < 0 ) return 0;
            if( catch(item = new("/world/book/know1.c")) ) return 0;
            if( item->move(me) ) {
                message_vision("$N清點$n後說道﹕"HIG"幹的好！下次再找你幫忙喔！\n"NOR, this_object(), ob);
            } else {
                if( item->move(environment(me)) ) {
                    message_vision("$N清點$n後說道﹕"HIG"幹的好！下次再找你幫忙喔！\n"NOR, this_object(), ob);
                    message_vision("$N說道﹕$n身上太重啦，幫你放在地上。\n"NOR, this_object(), me);
                } else {
                    destruct(item);
                    return 0;
                }
            }
            do_chat(( : destruct , ob : ));
            me->delete_temp("quest/spiderkill");
            break;
        default:
            do_chat((: command, "say 這是什麼鳥東西阿。" :));
            return 0;
            break;
    }
    return 1;
}
