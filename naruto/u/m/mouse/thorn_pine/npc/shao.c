#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "think" :),
        (: command, "say 「蒼之梟」真的太強了..." :),
        (: command, "say 想拿牠的「梟羽」來製作「新藥品」都很難..." :),
        (: command, "say 這下子該怎麼辦阿！" :),
        (: command, "scream" :),
    }) );
}
void create()
{
    set_name("豹簫" , ({ "bow shao", "shao" }));
    set_race("human");
    set("long", "因為以研究蒼之梟為生，所以自稱簫。\n");
    set_level(60);
    set("nickname","藥者");
    set("gender","male");
    set("age",45);
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "蒼之梟" )  {
        do_chat(({ 
            (: command, "say 牠就在轟天瀑的下面！" :),
            (: command, "say 小心點喔！牠可是非常厲害的！" :),
        }));
        return;
    }
    if( arg == "新藥品" || arg == "藥品" )  {
        do_chat(({ 
            (: command, "say 是我正在研製的新藥。" :),
            (: command, "peer" :),
            (: command, "say 可千萬不能被老哥聽到！不然他又要罵我糟蹋藥品。" :),
            (: command, "?" :),
            (: command, "say 我哥是誰？就是藥店的豹畢阿！這還看不出來。" :),
        }));
        return;
    }
    if( arg == "梟羽" )  {
        if( this_player()->query_temp("quest/helpowl") == 1) {
        do_chat(({ 
            (: command, "say 你可以慢慢考慮。" :),
            (: command, "say 不想幫忙就說「不幫」" :),
        }));
        return;
        } else
        if( this_player()->query_temp("quest/helpowl") == 2) {
            do_chat(({ 
                (: command, "say 了解蒼之梟的強大了吧？" :),
                (: command, "say 害怕可以「停止」繼續幫忙我。" :),
            }));
            return;
        }
        this_player()->add_temp("quest/helpowl", 1);
        do_chat(({ 
            (: command, "think" :),
            (: command, "say 再給你一點時間考慮好了。" :),
            (: command, "say 畢竟蒼之梟非常的強大！一般人大概無法與牠匹敵！" :),
            (: command, "say 願意的話就「幫忙」我吧！" :),
            (: command, "say 不願意就回答「不幫」" :),
        }));
        return;
    }
    if( arg == "幫忙" || arg == "幫你" ) {
        if( this_player()->query_temp("quest/helpowl") == 2) {
            do_chat(({ 
                (: command, "say 你已經在幫我了！" :),
            }));
            return;
        } else
        if( this_player()->query_temp("quest/helpowl") == 1) {
            this_player()->add_temp("quest/helpowl", 1);
            do_chat(({ 
                (: command, "fear" :),
                (: command, "say 那一切就靠你了！千萬別逞強阿！" :),
                (: command, "ah" :),
                (: command, "say 忘了說...獎勵是我還在實驗的藥品！" :),
                (: command, "say 一根梟羽可以換兩顆..." :),
                (: command, "say 絕對安全可以放心食用！" :),
            }));
            return;
        } else {
            do_chat(({ 
                (: command, "?" :),
                (: command, "say 現在是什麼情況？" :),
            }));
            return;
        }
    }
    if( arg == "停止" || arg == "不幫" )  {
        if( this_player()->query_temp("quest/helpowl") < 1) {
            do_chat(({ 
                (: command, "?" :),
                (: command, "say 我沒有請你幫我吧。" :),
            }));
        } else {
        this_player()->delete_temp("quest/helpowl");
            do_chat(({ 
                (: command, "nod" :),
                (: command, "say 沒關係...這任務真的太難了。" :),
            }));
            return;
        }
    }
}
int give_check(object ob)
{
    if( ob->id("_OWL_PLUME_") ) return 1;    // 梟羽
    else return 0;
}
int accept_object(object me, object ob)
{
    int amount, i;
    object item;

    amount = ob->query_amount()*2;

    if( is_busy() ) {
        do_chat((: command, "say 太忙了！等等！" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 誰來救救我阿！" :));
        return 0;
    }
    i = random(3)+1;
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/helpowl") == 2) {
                if( amount < 1 ) {
                    do_chat((: command, "say 起碼要給我一個以上的梟羽。" :));
                    return 0;
                }
                if( i == 3 ) {
                    if( file_size(__DIR__"item/god_pill.c") < 0 ) return 0;
                    if( catch(item = new(__DIR__"item/god_pill.c")) ) return 0;
                } else
                if( i == 2 ) {
                    if( file_size(__DIR__"item/ghost_pill.c") < 0 ) return 0;
                    if( catch(item = new(__DIR__"item/ghost_pill.c")) ) return 0;
                } else
                if( i == 1 ) {
                    if( file_size(__DIR__"item/man_pill.c") < 0 ) return 0;
                    if( catch(item = new(__DIR__"item/man_pill.c")) ) return 0;
                }
                if( amount ) {
                    if( function_exists("set_amount", ob) ) {
                    item->set_amount(amount);
                    } else
                    if( function_exists("set_volume", ob) ) {
                        item->set_volume(amount);
                    }
                }
                if( item->move(me) ) {
                    message_vision("$N說道﹕"HIG"太感謝$n了！\n"NOR, this_object(), me);
                    message_vision("$N說道﹕"HIG"這是獎勵，共"NOR"("HIY+amount+NOR")"HIG"個"+item->name()+"。\n"NOR, this_object(), me);
                } else
                if( item->move(environment(me)) ) {
                    message_vision("$N說道﹕"HIG"太感謝$n了！\n"NOR, this_object(), me);
                    message_vision("$N說道﹕"HIG"這是獎勵，共"NOR"("HIY+amount+HIG")"HIG"個"+item->name()+"。太重放地上喔。\n"NOR, this_object(), me);
                } else {
                    destruct(item);
                    return 0;
                }
                ob->set_amount(0);
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N說道﹕"HIG"我好像沒請你幫忙！\n"NOR, this_object(), me);
            break;
        default:
            do_chat((: command, "say 這不是梟羽！我研究了幾十年不會看錯的！" :));
            break;
    }
    return 1;
}
