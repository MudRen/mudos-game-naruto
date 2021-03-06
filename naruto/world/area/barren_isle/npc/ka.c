#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "sigh" :),
        (: command, "say 我的「寶箱」阿..." :),
    }) );
}
void create()
{
    set_name("卡蒙", ({ "ka meng", "meng" }));
    set_race("human");
    set_level(5);

    set("long", "除了頭部以外全身都被卡在寶箱中，只有手腳勉強能活動的怪人。\n");
    set("nickname", HIG"寶箱人"NOR);

    set("age", 34);
    set("gender", "male");

    // 一般時動作
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}

// 當char用say指令時，此mob的回應
int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "寶箱人" ) {
        do_chat( ({
            (: command, "say 我本來也是海賊團的成員。" :),
            (: command, "say 當初船長認為這座島上有大量寶藏！" :),
            (: command, "say 於是我們便下船不斷的尋找，但是最後還是無功而返。" :),
            (: command, "say 我們唯一沒有找過的地方，就是島上一個巨大的岩塊。" :),
            (: command, "say 不過那裡十分陡峭，根本無法上去。" :),
            (: command, "say 我下定決心冒險爬上岩塊，終於看到頂上似乎有幾個寶箱！" :),
            (: command, "say 也許是我太興奮了...居然從那上面跌了下來。" :),
            (: command, "say 結果掉進一個箱子裡面...變成現在這樣，人也昏了過去。" :),
            (: command, "say 等醒來時，船早就已經走遠了。" :),
            (: command, "say 於是只好留在這座島上，和動物一起生活。" :),
        }) );
    }
    if( arg == "寶箱" ) {
        do_chat( ({
            (: command, "say 前幾天跑來一個頭帶草帽骷髏旗的海賊團。" :),
            (: command, "say 他們的船長幫我把岩塊上的箱子都拿下來了喔！" :),
            (: command, "say 雖然是空的很讓人難過，但是那曾經裝滿了我的夢想！" :),
            (: command, "cac" :),
            (: command, "say 結果昨天跑來一群海賊，把箱子都搶走了！" :),
            (: command, "say 有沒有人能「幫助」我奪回來阿！！" :),
            (: command, "cry" :),
        }) );
    }
    if( arg == "幫助" || arg == "幫" ) {
        if( me->query_level() < 20 ) {
            do_chat( ({
                (: command, "shake" :),
                (: command, "say "+me->query("name")+"應該打不贏裡面那群兇惡的海賊。" :),
                (: command, "say 我不能讓無辜的人進去送死。" :),
            }) );
            return 1;
        }
        if( me->query_class() != "work_sea" && me->query_class() != "little_sea" ) {
            do_chat( ({
                (: command, "wa" :),
                (: command, "say 這種小事我自己來就可以了！" :),
                (: command, "say 不需要勞煩"+me->query("name")+"啦！" :),
            }) );
            return 1;
        }
        if( me->query_temp("piece_test") ) {
            do_chat( ({
                (: command, "say "+me->query("name")+"不是答應要幫我了嗎！" :),
                (: command, "say 如果忘記要拿什麼就再說一次吧！" :),
                (: command, "say 幫我拿回紅寶箱跟藍寶箱，或是同種顏色三個也可以。" :),
            }) );
            return 1;
        }
        do_chat( ({
            (: command, "say 願意幫助我嗎！真是太棒了！" :),
            (: command, "say 那群海賊就在南邊的垚圈裡面。" :),
            (: command, "say 幫我拿回紅寶箱跟藍寶箱，或是同種顏色的寶箱三個也可以！" :),
            (: command, "say 一切就拜託"+me->query("name")+"了！" :),
            (: command, "addoil" :),
        }) );
        me->set_temp("piece_test", 1);
    }
    return 1;
}
int accept_kill(object ob)
{
    this_player()->remove_all_killer();
    do_chat((: command, "say 找寶箱比較重要..." :));
    return 1;
}
int accept_fight(object ob)
{
    do_chat((: command, "say 找寶箱比較重要..." :));
    return 0;
}
int accept_object(object me, object item)
{
    int pass=0;

    if( !objectp(me) || !objectp(item) ) return 0;
    if( !item->query("piece_test") ) return 0;

    if( me->query_level() < 20 ) {
        do_chat( ({
            (: command, "say "+me->query("name")+"應該打不贏那群海賊吧！哪來的箱子！" :),
        }) );
        return 0;
    }
    if( me->query_class() != "work_sea" && me->query_class() != "little_sea" ) {
        do_chat( ({
            (: command, "say 雖然很像我的箱子！但我不能收。" :),
        }) );
        return 0;
    }
    if( !me->query_temp("piece_test") ) {
        do_chat( ({
            (: command, "say 我並沒有拜託"+me->query("name")+"幫我拿箱子，我不能收。" :),
        }) );
        return 0;
    }
    message_vision("$N看見"+item->query("name")+"高興地大喊："HIG"就是這個沒錯！$n幹的太好了！\n"NOR, this_object(), me);

    if( item->query("piece_test") == 1 ) me->add_temp("piece_test_b1", 1);
    if( item->query("piece_test") == 2 ) me->add_temp("piece_test_b2", 1);

    if( me->query_temp("piece_test_b1") >= 3 ) pass = 1;
    if( me->query_temp("piece_test_b2") >= 3 ) pass = 1;
    if( me->query_temp("piece_test_b1") >=1 && me->query_temp("piece_test_b2") >=1 ) pass = 1;

    if( pass ) {
        me->delete_temp("piece_test");
        me->delete_temp("piece_test_b1");
        me->delete_temp("piece_test_b2");

        call_out("pass_1", 5, this_object());
        if( me->query_class() == "work_sea" ) {
            message_vision("$N說道："HIG"非常感謝$n幫忙！海軍果然是最可靠的阿！\n"NOR, this_object(), me);
            tell_object(me, "\n\n你所做的行為被海軍總部得知，榮升為"HIC"「海軍士兵」"NOR"了！\n\n");
            me->set_class("soldier_sea");
        } else if( me->query_class() == "little_sea" ) {
            message_vision("$N說道："HIG"非常感謝$n幫忙！如果海賊都像$n一樣就好啦！\n"NOR, this_object(), me);
            tell_object(me, "\n\n因為在奪寶箱中你殺了許多有懸賞金的海賊，被世界政府列為"HIR"「海賊」"NOR"了！\n\n");
            me->set_class("thief_sea");
        } else {
            message_vision(HIR"\n發生錯誤啦！快找巫師來處理。\n\n"NOR, this_object());
        }
    }
    // 使用 do_chat 來延遲呼叫 destruct 先讓 give 動作完成
    do_chat((: destruct, item :));
    return 1;
}
