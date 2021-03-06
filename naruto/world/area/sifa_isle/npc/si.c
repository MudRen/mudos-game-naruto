#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say 要「加入」海軍的人就來找我英雄"+this_object()->query("name")+"吧！" :),
        (: command, "say 我就是即將成為海軍英雄的大人物阿！" :),
    }) );
}
void create()
{
    set_name("斯潘達姆", ({ "si pan da mu", "si", "pan", "da", "mu"}) );
    set_race("human");
    set_level(5);
    set_class("general_sea");  // 海軍准將
    set("age", 28);
    set("title", HIR"ＣＰ９長官"NOR);
    set("long", "臉上用鐵製的器具所保護，似乎曾經受到過嚴重的傷害。他就是海軍\n"
                "諜報機構ＣＰ９的長官斯潘達姆。雖然他是長官，不過根據海兵們所\n"
                "說，他完全不會ＣＰ９特殊招式「六式」，連一般的海兵都打不贏。\n");

    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}
// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    object test;

    if( arg == "加入" || arg == "加入海軍" ) {
        if( me->query("guild") == 0 ) {
            do_chat( ({ 
                (: command, "say "+this_player()->query("name")+"先去海軍報到處登記吧！" :),
            }) );
            return 1;
        }
        if( me->query("guild") != "piece" ) {
            do_chat( ({ 
                (: command, "shake" :),
                (: command, "say "+this_player()->query("name")+"已經加入其他組織了！" :),
                (: command, "say 身為海軍不准有多重身份！" :),
            }) );
            return 1;
        }
        if( me->query_class() != "commoner" ) {
            do_chat( ({ 
                (: command, "say "+this_player()->query("name")+"已經擁有職業了！" :),
                (: command, "say 身為海軍不准身兼多職！" :),
            }) );
            return 1;
        }
        if( me->query_temp("quest/mitp") ) {
            do_chat( ({ 
                (: command, "say "+this_player()->query("name")+"已經有拿測試卷了！" :),
                (: command, "say 身為海軍不准身兼多職！" :),
            }) );
            return 1;
        }
        test = new( __DIR__"item/paper.c" );
        if( !objectp(test) ) {
            do_chat( ({
                (: command, "say 糟糕！一不小心把考卷都發光了！" :),
                (: command, "say 那些雜兵在搞什麼鬼！還不送新測試卷過來！" :),
            }) );
            return 1;
        }
        if( !test->move(this_object()) ) {
            do_chat( ({ 
                (: command, "ah" :),
                (: command, "say 測試卷擺哪去了！" :),
            }) );
            destruct(test);
            return 1;
        }
        // 設定玩家暫時變數，以防一直領考卷
        if( test->move(me) ) {
            me->set_temp("quest/mitp", 1);
            do_chat( ({ 
                (: command, "say 測試卷交給"+this_player()->query("name")+"了！寫完就給我吧。" :),
                (: command, "say 如果沒全部答對不准加入海軍！" :),
            }) );
        } else if( test->move(environment(me)) ) {
            do_chat( ({ 
                (: command, "say "+this_player()->query("name")+"身上太重！考試卷我放在地上，寫完就給我吧。" :),
                (: command, "say 如果沒全部答對不准加入海軍！" :),
            }) );
        } else {
            destruct(test);
            return 0;
        }
    }
    return 1;
}

int accept_object(object me, object item)
{
    int score;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( item->is_test_paper() != "piece" ) return 0;

    if( me->query("guild") != "piece" ) {
        message_vision("$N說道﹕"HIG"$n好像是其他組織的人。！\n"NOR, this_object(), me);
        return 0;
    }
    if( me->query_class() != "commoner" ) {
        message_vision("$N說道﹕"HIG"$n已經有職業了吧！？\n"NOR, this_object(), me);
        message_vision("$N說道﹕"HIG"當我$N這麼好騙嗎！\n"NOR, this_object(), me);
        return 0;
    }
    score = item->do_check();
    message_vision("$N盯著$n猛看...嘴中不停碎碎唸著...\n", this_object(), item);

    if( score != 100 ) {
        message_vision("$N說道﹕"HIG"$n真是太差勁了！\n"NOR, this_object(), me);
        message_vision("$N說道﹕"HIG"只考"+chinese_number(score)+"分也想加入海軍？\n"NOR, this_object(), me);
        return 0;
    }
    message_vision("$N說道﹕"HIG"寫的不錯！我同意$n加入啦！\n"NOR, this_object(), me);
    message_vision("$N說道﹕"HIG"從今天開始$n就是海軍的一員了！\n"NOR, this_object(), me);
    message_vision("$N說道﹕"HIG"要好好保護我的安全阿！\n"NOR, this_object(), me);
    me->set("title", "世界政府海軍");
    me->addCamp("police");  // 增加海軍陣營
    me->set_level(1);
    me->set_class("work_sea");

    // 使用 do_chat 來延遲呼叫 destruct 先讓 give 動作完成
    do_chat((: destruct, item :));
    return 1;
}
