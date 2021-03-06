#include <npc.h>
#include <ansi.h>

void to_do_say()
{
    do_chat( ({ 
        (: command, "say 這裡原本只是給犯規豹人暫住的地方。" :),
        (: command, "say 後來族長答應讓獵人協會在這開闢考試場地。" :),
        (: command, "say 當然不能讓他們睡路邊吧！就變成旅館啦！" :),
        (: command, "say 價錢絕對公道喔！有興趣可以向我詢問「住宿」" :),
        (: command, "snicker" :),
    }) );
}
void create()
{
    set_name("豹爛" , ({ "bow line", "line" }) );
    set_race("human");
    set("long", "希望每天都如四周環境一樣燦爛，故有此名。\n");
    set_level(40);
    set("gender", "male");
    set("camp", "bow");
    set("nickname", "旅館老闆" );
    set("age", 60);
    // 一般時動作
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "住宿" )  {
        do_chat( ({
            (: command, "wink " + this_player()->query("id") :),
            (: command, "say 一樓是給那些犯規的豹人住的啦。" :),
            (: command, "say 當然不可能給客人住阿！" :),
            (: command, "lick" :),
            (: command, "say 如果想住宿休息，起碼銀行要有10000兩銀子喔！" :),
            (: command, "say 然後辦理手續(lodging)就可以啦！" :),
            (: command, "say 只要有錢！絕對歡迎！" :),
        }) );
        return;
    }
}
