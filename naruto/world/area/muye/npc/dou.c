#include <npc.h>

inherit F_FIGHTER;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say 想要「參加」中忍的考試嗎！？" :),
        (: command, "say 有實力的下忍皆可以報名參加！" :),
    }) );
}

void create()
{
    set_name("御手洗紅豆", ({ "dou" }));
    set_race("human");
    set_level(60);
    set("camp", "muye");
    set("long", "脖子上的咒印，似乎與大蛇丸有牽連。\n");

    set("age", 24);
    set("gender", "female");

    // 一般時動作
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    setup();
}

// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "參加" || arg == "參加考試" ) {
        if( me->query_level() < 20 ) {
            this_object()->force_me("say " + me->query("name") + "，你的實力明顯的不足，不能讓你參加中忍考試。");
            return 1;
        }

        if( me->query_class() != "inferior") {
            this_object()->force_me("say " + me->query("name") + "，只有下忍才能參加考試哦。");
            return 1;
        }

        if( me->query_temp("middle_test") ) {
            this_object()->force_me("say " + me->query("name") + "，你已經參加中忍考試了。");
            return 1;
        }

        this_object()->force_me("say 很好很好！" + me->query("name") + "去森林裡拿天之書與地之書給我。");
        this_object()->force_me("say 當湊齊這二樣東西後，方可證明你有擔任中忍的實力，加油吧！");
        this_object()->force_me("say 若湊齊三本天之書或三本地之書，亦可以證明你的實力！");

        me->set_temp("middle_test", 1);
    }

    return 1;
}

int accept_object(object me, object item)
{
    int pass=0;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( !item->query("middle_test") ) return 0;

    if( me->query_level() < 20 ) {
        this_object()->force_me("say " + me->query("name") + "，你的實力明顯的不足，不能讓你參加中忍考試。");
        return 0;
    }

    if( me->query_class() != "inferior") {
        this_object()->force_me("say " + me->query("name") + "，只有下忍才能參加考試哦。");
        return 0;
    }

    if( !me->query_temp("middle_test") ) {
        this_object()->force_me("say " + me->query("name") + "，你沒有參加中忍考試了。");
        return 0;
    }

    message_vision("$N接過$n給的"+ item->query("name") +"說道：嗯...不錯不錯！\n", this_object(), me);

    if( item->query("middle_test") == 1 ) me->add_temp("middle_test_b1", 1);
    if( item->query("middle_test") == 2 ) me->add_temp("middle_test_b2", 1);

    if( me->query_temp("middle_test_b1") >= 3 ) pass = 1;
    if( me->query_temp("middle_test_b2") >= 3 ) pass = 1;
    if( me->query_temp("middle_test_b1") >=1 && me->query_temp("middle_test_b2") >=1 ) pass = 1;

    if( pass ) {
    	me->delete_temp("middle_test");
    	me->delete_temp("middle_test_b1");
    	me->delete_temp("middle_test_b2");
        this_object()->force_me("say 很好！" + me->name() + "你從今以後就是中忍了！");
        this_object()->force_me("cong " + me->query_id());
        me->set_class("middle");
    }

    // 使用 do_chat 來延遲呼叫 destruct 先讓 give 動作完成
    do_chat((: destruct, item :));

    return 1;
}
