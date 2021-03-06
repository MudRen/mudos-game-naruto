#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void create()
{
    set_name("童角", ({ "ton gau", "gau" }) );
    set_level(60);
    set_class("superior");
    set_race("human");
    set("gender", "male");
    set("age", 25);
    set("long","木葉醫療忍者，似乎正在等人來幫助他。\n");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: command, "say 委託的燈籠任務怎麼都沒人要幫忙呢...":),
    }));
    setup();
}
void relay_say(object ob, string arg)
{
    object item;

    if( arg == "燈籠" || arg == "燈籠任務" || arg == "委託" )  {
        do_chat(({
            (: command, "nod" :),
            (: command, "say 就是戰事林通倍利所拿的燈籠。" :),
            (: command, "say 聽說據有神奇的療傷效果。" :),
            (: command, "say 所以我想拿回來研究。" :),
            (: command, "say 不過我以前就認識大蛇丸，就這樣跑去一定會被攻擊的。" :),
            (: command, "say 因為這樣我對燈籠的事也是一知半解。" :),
            (: command, "sigh" :),
            (: command, "say 所以必須拜託一些生面孔去拿才行。" :),
            (: command, "say 到附近的『骸骨戰場』找「竹取一族」" :),
            (: command, "say 他們是大蛇丸旗下的一支族群。" :),
            (: command, "say 大蛇丸就是派他們去拿燈籠的，所以問他們應該會更清楚。" :),
        }));
        return;
    }
    if( arg == "骸骨戰場" || arg == "竹取一族" )  {
        do_chat(({
            (: command, "hmm" :),
            (: command, "say 地圖會看吧？" :),
            (: command, "say 就是 help world 啦。" :),
            (: command, "say 骸骨戰場就在左上角。" :),
            (: command, "say 竹取一族當然就在那邊。" :),
            (: command, "ah" :),
            (: command, "say 對了..." :),
            (: command, "say 千萬別跟竹取一族的人起衝突阿..." :),
            (: command, "say 他們以前被稱為惡魔一族..是很危險的族群。" :),
        }));
        return;
    }
    if( arg == "天氣預測表" )  {
        item = new("/world/area/ship/npc/item/paper.c");
        if( item->move(this_player()) )
            tell_object(this_player(), HIY"(你獲得了一張天氣預測表。)\n"NOR);
        else {
            if( environment(this_player())->is_area() ) move_side(item, this_player());
            else item->move(environment(this_player()));
            tell_object(this_player(), HIY"(你獲得了一張天氣預測表，但是掉在地上了。)\n"NOR);
        }
        do_chat(({
            (: command, "say 想要知道最近天氣？" :),
            (: command, "say 這就是表單，拿去吧。" :),
        }));
        return;
    }
}
