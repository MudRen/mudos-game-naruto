// write by -Acme-

#include <npc.h>

inherit F_VILLAGER;
inherit F_TRAINER;    // 訓練忍者

/* guild: muye   木葉忍者村
          yinyin 音隱忍者村
          wuyin  霧隱忍者村
          shayin 砂隱忍者村
          yuyin  雨隱忍者村
          yunyin 雲隱忍者村
          caoyin 草隱忍者村
          puyin  瀑隱忍者村
*/

void to_do_say()
{
    do_chat( ({ 
        (: command, "say 想成為木葉村的一員嗎？歡迎各方好漢「加入」！" :),
        (: command, "say 當你參加忍者學校「畢業考」得滿分後，即可成為下忍！" :),
        (: command, "say 成為木葉村的一員後，便可以在忍者學校學習基本技能。" :),
    }) );
}

void create()
{
    set_name("伊魯卡", ({ "yi lu ka", "ka" }) );
    set_race("human");
    set_level(40);
    set_class("middle");  //中忍
    set("age", 25);
    set("camp", "muye");
    set("title", "木葉忍者學校教師");
    set("long", "伊魯卡是一名培育木葉村內未來戰鬥力的忍者學校教師，平時以教學\n"
                "為主，但當有任務時，也會盡中忍的責任。擁有優秀才能令他順利完\n"
                "成幾項Ａ級任務，備受高層信賴，因此被挑選成為教師，但對少年時\n"
                "代曾經歷孤獨的伊魯卡來說，教師的工作比任務更加適合他。\n"
                "若你是木葉村的忍者，可以利用 train 指令來向伊魯卡學習技能。\n"
                "使用 list 指令查詢可學習的技能列表。\n" );

    // 一般時動作
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    // 設定忍者村，相同的忍者村才會教
    set("guild", "muye");

    // 設定能訓練的技能
    //
    // set_train(技能名, 是否可直接習得, 學習該技能所需要的角色等級, 此技能可學習到的上限等級)
    //
    // 當玩家沒有該技能時，若"是否可直接習得"這個設定值為非零值時，玩家向訓練者學習時則可記住
    // 這個技能到lv1，而有lv的技能才可以投點繼續鍛練。故可用於特殊技，要解謎得到lv後方可訓練。
    //
    set_train_with_camp("combat", 1, 1, 160, "muye", -2);             // 格鬥技巧
    set_train_with_camp("dodge", 1, 1, 160, "muye", -2);              // 閃躲技巧
    set_train_with_camp("parry", 1, 1, 160, "muye", -2);              // 擋格技巧
    set_train_with_camp("heavy hit", 1, 5, 140, "muye", -2);          // 重擊之術
    set_train_with_camp("savage hit", 1, 5, 140, "muye", -2);         // 暴擊之術
    set_train_with_camp("continual hit", 1, 5, 140, "muye", -2);      // 連擊之術
    set_train_with_camp("force", 1, 10, 120, "muye", -2);             // 體術
    set_train_with_camp("ninja", 1, 10, 120, "muye", -2);             // 忍術
    set_train_with_camp("substitute", 1, 10, 120, "muye", 0);         // 忍術：替身術
    set_train_with_camp("muye wind", 1, 15, 120, "muye", -1);         // 體術：木之葉烈風
    set_train_with_camp("alter ego", 1, 15, 120, "muye", -1);         // 忍術：分身術
    set_train_with_camp("hundred palm", 1, 15, 120, "muye", -1);      // 體術：百烈掌
    set_train_with_camp("animal taming", 1, 15, 120, "muye", -1);     // 忍術：馴獸術
    set_train_with_camp("double physique", 1, 15, 120, "muye", -1);   // 忍術：倍化術
    set_train_with_camp("cell activation", 1, 15, 120, "muye", -1);   // 忍術：細胞活化

    setup();

    set_skill("substitute", 100);          // 忍術： 替身術
    map_skill("dodge", "substitute");      // 使用技能「替身術」於迴避技巧上
}

// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "加入" || arg == "加入木葉村" ) {
        if( me->query("guild") ) {
            if( me->query("guild") == "muye") this_object()->force_me("say " + me->query("name") + "，你已經是木葉村成員了。");
            else this_object()->force_me("say " + me->query("name") + "，你已經是別的忍者村成員了。");
            return 1;
        }
        this_object()->force_me("say 很好很好！從今以後 " + me->query("name") + " 就是我們木葉村的一員了！");
        me->set("guild", "muye");
        me->set("title", "木葉村成員");
        return 1;
    }

    if( arg == "畢業考" || arg == "參加畢業考" ) {
        object test;
        if( me->query("guild") != "muye" ) {
            this_object()->force_me("say " + me->query("name") + "，你不是我們木葉村的成員，不能參加畢業考哦。");
            return 1;
        }

        if( me->query_class() != "commoner" ) {
            this_object()->force_me("say " + me->query("name") + "，忍者學校畢業考只適用於一般的平民哦。");
            return 1;
        }

        if( me->query_temp("quest/mitp") ) {
            this_object()->force_me("say " + me->query("name") + "，你剛不是已經跟我拿過考卷了？");
            return 1;
        }

        test = new( _DIR_ITEM_"mitp.c" );
        if( !objectp(test) ) {
            this_object()->force_me("say " + me->query("name") + "，畢業考的考試卷用完了。");
            return 1;
        }

        if( !test->move(this_object()) ) {
            this_object()->force_me("say " + me->query("name") + "，唉呀！我忘了拿考試卷出來。");
            destruct(test);
            return 1;
        }

        // 設定玩家暫時變數，以防一直領考卷
        me->set_temp("quest/mitp", 1);

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
    if( item->is_test_paper() != "muye" ) return 0;

    if( me->query("guild") != "muye" ) {
        this_object()->force_me("say " + me->query("name") + "，你不是木葉村的一員。");
        return 0;
    }
    
    if( me->query_class() != "commoner" ) {
        this_object()->force_me("say " + me->query("name") + "，忍者學校畢業考只適用於一般的平民哦。");
        return 0;
    }

    score = item->do_check();

    message_vision("$N雙眼快速地掃瞄著$n...\n", this_object(), item);

    if( score != 100 ) {
        this_object()->force_me("say 什麼！？只考" + chinese_number(score) + "分也想從忍者學校畢業！？");
        return 0;
    }
    this_object()->force_me("say 不錯不錯！考了一百分，" + me->name() + "你從今以後就是木葉村的下忍了！");
    this_object()->force_me("cong " + me->query_id());

    me->set("title", "木葉村忍者");
    me->set_level(1);
    me->addCamp("muye");  // 增加木葉村陣營
    me->set_class("inferior");

    // 使用 do_chat 來延遲呼叫 destruct 先讓 give 動作完成
    do_chat((: destruct, item :));
    return 1;
}
