#include <npc.h>
#define CATEGORY    "level_e"
#define ID          2

inherit F_VILLAGER;

void create()
{
    set_name("吉田小姐", ({ "ji tian", "tian" }));
    set_race("human");
    set_level(5);
    
    set("long", "吉田小姐長得白白胖胖的，不知在忙什麼在那走來走去。\n");
    set("camp", "muye");
    set("age", 23);
    set("gender", "female");
    
    // 一般時動作
    set("chat_chance", 1);
    set("chat_msg", ({
        (: command, "say 忙死了！忙死了！" :),
    }) );

    setup();
}

/* 暫時先關掉摟
// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "幫忙" || arg == "溜狗" || arg == "幫忙溜狗") {
        if( me->query_score("elevel") >= 100 ) {
            tell_object(me, "吉田小姐似乎不太想理你。\n");
            return 0;
         }
        if( !me->query_quest(CATEGORY, ID) ) {
            object pet;
            if( !objectp(pet = new(__DIR__"pet.c")) ) {
                this_object()->force_me("say 我的狗已經給別人溜光光了，下次請早！");
                return 1;
            }
            this_object()->force_me("say 你來幫忙溜狗的啊，這條狗幫我拿去溜一溜吧！");
            this_object()->force_me("say 當你「溜完了」過來跟我說！");
            switch( random(5) ) {
                case 0: pet->set("name", "大隻犬"); break;
                case 1: pet->set("name", "鬥牛犬"); break;
                case 2: pet->set("name", "小花"); break;
                case 3: pet->set("name", "小黑"); break;
                case 4: pet->set("name", "大狼犬"); break;
            }
            pet->move(environment(me));
            pet->set_leader(me);
            me->add_quest(CATEGORY, ID, 1);
            me->set_temp("quest/" + CATEGORY+ID, pet);
            return 1;
        }
        
        if( me->query_quest(CATEGORY, ID) == 1 ) {
            this_object()->force_me("say 剛不是叫你溜了嗎？還不快去幫我溜狗。");
            this_object()->force_me("say 當你「溜完了」過來跟我說！");
            return 1;
        }
        return 1;
    }

    if( arg == "溜完了" ) {

        if( !me->query_quest(CATEGORY, ID) ) {
            this_object()->force_me("say 我有請你來溜狗嗎？");
        } else {
            object pet;
            if( !objectp(pet = me->query_temp("quest/" + CATEGORY + ID)) ) {
                this_object()->force_me("say 什麼！？你把我的狗搞丟了，搞什麼鬼！！");
                // 移除暫存的資料
                me->delete_quest(CATEGORY, ID);
                return 1;
            }

            if( pet->query("move_count") < 100 ) {
                this_object()->force_me("say 什麼！？你溜那二、三步路叫做溜好了？快去給我溜！");
                return 1;
            }

            this_object()->force_me("say 嗯，溜的很好，這裡一百兩賞金拿去吧！");
            this_object()->force_me("thank " + me->query_id());
            tell_object(me, "(一百兩銀子已經自動存在銀行裡。)\n");
            me->add("bank", 100);

            // 加e級任務1點
            me->gain_score("elevel",1);
                    
            // 移除暫存的資料
            me->delete_temp("quest/" + CATEGORY + ID);
            me->delete_quest(CATEGORY, ID);
            destruct(pet);
        }
        return 1;
    }
    return 1;
} */
