#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "sweat" :),
        (: command, "say 我正在這裡收集樹液做藥材研究。" :),
        (: command, "say 不過外面的刺林害我到處都是受傷。" :),
        (: command, "say 再跑出去搞不好沒命回來了！" :),
        (: command, "sigh" :),
    }) );
}
void create()
{
    set_name("石燕士" , ({ "dr. sz", "sz" }));
    set_race("human");
    set("long", "身穿白袍的男子，身上到處都是傷。\n");
    set_level(61);
    set("title",HIW"白袍醫者"NOR);
    set("gender","male");
    set("age",25);
    set("chat_chance", 5);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
    carry_object(__DIR__"eq/cloth.c")->wear();
}
void relay_say(object ob, string arg)
{
    if( arg == "刺林" )  {
        do_chat(({ 
            (: command, "say 你都到這裡了應該領教過吧？" :),
            (: command, "say 被那些刺林刺到還真是痛呢！" :),
        }));
        return;
    }
    if( arg == "藥材" || arg == "研究" )  {
        do_chat(({ 
            (: command, "say 聽說這刺松林的後面還有片豹族的村子。" :),
            (: command, "say 牠們受傷都是用這樹液來治療喔！" :),
            (: command, "say 所以我來這裡做研究。" :),
            (: command, "say 希望精製的樹液能比原來的效果更好！" :),
        }));
        return;
    }
    if( arg == "樹液" )  {
        if( this_player()->query_temp("quest/helpwater") == 1) {
        do_chat(({ 
            (: command, "say 你還沒回答我阿？" :),
            (: command, "say 不想幫忙就說「不幫」" :),
        }));
        return;
        } else
        if( this_player()->query_temp("quest/helpwater") == 2) {
            do_chat(({ 
                (: command, "say 不想幫我了嗎？" :),
                (: command, "say 那就「停止」繼續幫忙我吧。" :),
            }));
            return;
        }
        this_player()->add_temp("quest/helpwater", 1);
        do_chat(({ 
            (: command, "say 喔喔！你可以幫助我嗎？" :),
            (: command, "say 打死外面的樹人都會掉樹液。" :),
            (: command, "say 拿來給我就可以了！" :),
            (: command, "say 願意的話就「幫忙」我吧！" :),
        }));
        return;
    }
    if( arg == "幫忙" || arg == "幫你" ) {
        if( this_player()->query_temp("quest/helpwater") == 2) {
            do_chat(({ 
                (: command, "say 你已經要幫我了不是嗎！" :),
                (: command, "say 放心吧！等你拿回來獎勵少不了的。" :),
                (: command, "say 不想幫忙就「停止」幫助我吧。" :),
            }));
            return;
        } else
        if( this_player()->query_temp("quest/helpwater") == 1) {
            this_player()->add_temp("quest/helpwater", 1);
            do_chat(({ 
                (: command, "dance" :),
                (: command, "say 一切拜託你了！" :),
            }));
            return;
        } else {
            do_chat(({ 
                (: command, "?" :),
                (: command, "say 沒事別打擾我做實驗。" :),
            }));
            return;
        }
    }
    if( arg == "停止" || arg == "不幫" )  {
        if( this_player()->query_temp("quest/helpwater") < 1) {
            do_chat(({ 
       
         (: command, "?" :),
                (: command, "say 我又沒找你幫忙。" :),
            }));
        } else {
        this_player()->delete_temp("quest/helpwater");
            do_chat(({ 
                (: command, "glare" :),
                (: command, "say 有誰能幫我呢..." :),
            }));
            return;
        }
    }
}
int give_check(object ob)
{
    if( ob->id("_HIG_WATER_") ) return 1;    // 綠色樹液
    if( ob->id("_HIM_WATER_") ) return 2;    // 紫色樹液
    if( ob->id("_HIR_WATER_") ) return 3;    // 紅色樹液
    if( ob->id("_HIY_WATER_") ) return 4;    // 黃金樹液
    else return 0;
}
int accept_object(object me, object ob)
{
    object item;
    if( is_busy() ) {
        do_chat((: command, "say 太忙了！等等！" :));
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say 誰來救救我阿！" :));
        return 0;
    }
    me->start_busy(1);
    this_object()->start_busy(1);
    switch( give_check(ob) ) {
        case 1:
            if( me->query_temp("quest/helpwater") == 2) {
                message_vision("$N高興的說道﹕"HIG"多謝你的樹液阿！\n"NOR, this_object(), me);
                tell_object(me, "(你的學習點數增加 " + 2*ob->query_amount() +" 點了。)\n");
                me->add_point("learn", 2*ob->query_amount() );
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N說道﹕"HIG"我好像沒請你幫忙！\n"NOR, this_object(), me);
            break;
        case 2:
            if( me->query_temp("quest/helpwater") == 2) {
                message_vision("$N高興的說道﹕"HIG"多謝你的樹液阿！\n"NOR, this_object(), me);
                tell_object(me, "(你的學習點數增加 " + 5*ob->query_amount() +" 點了。)\n");
                me->add_point("learn", 5*ob->query_amount() );
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N說道﹕"HIG"我好像沒請你幫忙！\n"NOR, this_object(), me);
            break;
        case 3:
            if( me->query_temp("quest/helpwater") == 2) {
                message_vision("$N高興的說道﹕"HIG"多謝你的樹液阿！\n"NOR, this_object(), me);
                tell_object(me, "(你的學習點數增加 " + 10*ob->query_amount() +" 點了。)\n");
                me->add_point("learn", 10*ob->query_amount() );
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N說道﹕"HIG"我好像沒請你幫忙！\n"NOR, this_object(), me);
            break;
        case 4:
            if( me->query_temp("quest/helpwater") == 2) {
                message_vision("$N高興的說道﹕"HIG"多謝你的樹液阿！\n"NOR, this_object(), me);
                tell_object(me, "(你的學習點數增加 " + 50*ob->query_amount() +" 點了。)\n");
                me->add_point("learn", 50*ob->query_amount() );
                do_chat( ({ ( : destruct , ob : ), }) );
                break;
            }
            message_vision("$N說道﹕"HIG"我好像沒請你幫忙！\n"NOR, this_object(), me);
            break;
        default:
            do_chat((: command, "say 這好像不是樹液耶！" :));
            break;
    }
    return 1;
}
