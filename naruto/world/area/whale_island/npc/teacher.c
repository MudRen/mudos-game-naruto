/* guild: hunter  獵人 */
// write by Tmr 2005/10/22

#include <npc.h>

inherit F_VILLAGER;
inherit F_TRAINER;    // 訓練導師

void to_do_say()
{
    do_chat( ({ 
        (: command, "say 想報名本年度的獵人試驗嗎？本補習班有教無類，歡迎大家「報名」！" :),
        (: command, "say 只要你能通過本補習班的「模擬考」，就能成為無照獵人喔！！" :),
        (: command, "say 本補習班有專業人士，專門輔導無照獵人的基本訓練，做好最後的衝刺，一舉考到獵人執照！！" :),
        (: command, "say 來來來∼∼有交無類，有交錢就不分類，只要有心，人人都能成為獵人！！" :),
    }) );
}

void create()
{
    set_name("杭鐵管", ({ "hang tie-guan", "hang", "guan", "teacher"}) );
    set_race("human");
    set_level(40);
    set_class("hxh_intermediate");  //有照獵人
    set("age", 25);
    set("camp", "hunter");
    set("title", "獵人認証講師");
    set("long", "杭鐵管是一名具有正式講師資格，專門輔導獵人証照的培訓工作。\n"
                "若你具有無照獵人，則表示你具有參加獵人考試的資格。你可以利用\n"
                "train 指令來向杭鐵管學習技能。使用 list 指令查詢可學習的技能列表。\n" );

    // 一般時動作
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    // 只輔導獵人
    set("guild", "hunter");

    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 160, "hunter", -2);            // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 160, "hunter", -2);             // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 160, "hunter", -2);             // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 140, "hunter", -2);         // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 140, "hunter", -2);        // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 140, "hunter", -2);     // 連擊之術
    set_train_with_camp("strength", 1, 10, 120, "hunter", -2);         // 強化系
    set_train_with_camp("variation", 1, 10, 120, "hunter", -2);        // 變化系
    set_train_with_camp("operation", 1, 10, 120, "hunter", -2);        // 操作系
    set_train_with_camp("emit", 1, 10, 120, "hunter", -2);             // 放出系
    set_train_with_camp("concrete", 1, 10, 120, "hunter", -2);         // 具現系
    set_train_with_camp("special", 1, 10, 120, "hunter", -2);          // 特質系

    setup();

    // 人物本身的技能設定
    set_skill("solid", 100);               // 念技：堅
    map_skill("parry", "solid");    
}

// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "報名"  ) {
        if( me->query("guild") )
                return 0;
        this_object()->force_me("say 很好很好！從今以後 " + me->query("name") + " 就是我們的學員了！");
        me->set("guild", "hunter");
        me->set("title", "獵人考生");
        return 1;
    }   

    if( arg == "模擬考" || arg == "參加模擬考" ) {
        object test;
        if( me->query("guild") != "hunter" ) {
            this_object()->force_me("say " + me->query("name") + "，你不是我們的學員，不能參加模擬考哦。");
            return 1;
        }

        if( me->query_class() != "commoner" ) {
            this_object()->force_me("say " + me->query("name") + "，本補習班的模擬考只適用於一般的平民哦。");
            return 1;
        }

        if( me->query_temp("quest/hunter_exam") ) {
            this_object()->force_me("say " + me->query("name") + "，你剛不是已經跟我拿過考卷了？");
            return 1;
        }

        test = new( __DIR__"item/hunter_exam.c" );
        if( !objectp(test) ) {
            this_object()->force_me("say " + me->query("name") + "，模擬考的考試卷用完了。");
            return 1;
        }

        if( !test->move(this_object()) ) {
            this_object()->force_me("say " + me->query("name") + "，唉呀！我忘了拿考試卷出來。");
            destruct(test);
            return 1;
        }
        // 設定玩家暫時變數，以防一直領考卷
        me->set_temp("quest/hunter_exam", 1);

        this_object()->force_me("give paper to " + me->query_id()) ;
        this_object()->force_me("say " + me->query("name") + "，將考試卷上的答案填一填，完成後再拿給我。");
        return 1;
    }
    return 1;
}

int accept_object(object me, object item)
{
    int score;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( item->is_test_paper() != "hunter" ) return 0;

    if( me->query("guild") != "hunter" ) {
        this_object()->force_me("say " + me->query("name") + "，你並不是我們的學員，請先報名我們的課程吧。");
        return 0;
    }
    
    if( me->query_class() != "commoner" ) {
        this_object()->force_me("say " + me->query("name") + "，模擬考只適用於一般的平民哦。");
        return 0;
    }

    score = item->do_check();

    message_vision("$N雙眼快速地掃瞄著$n...\n", this_object(), item);

    if( score != 100 ) {
        this_object()->force_me("say 什麼！？只考" + chinese_number(score) + "分也想去考獵人執照！？");
        return 0;
    }
    this_object()->force_me("say 不錯不錯！考了滿分，" + me->name() + "你從今以後就擁有考獵人執照的資格了！！");
    this_object()->force_me("cong " + me->query_id());

    me->set("title", "念能力者");
    me->set_level(1);
    me->addCamp("hunter");  // 增加獵人公會陣營
    me->set_class("hxh_initial");

    // 使用 do_chat 來延遲呼叫 destruct 先讓 give 動作完成
    do_chat((: destruct, item :));

    return 1;
}
