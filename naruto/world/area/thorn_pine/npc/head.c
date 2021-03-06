#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void to_do_say()
{
    do_chat( ({
        (: command, "say 這些蒼之梟真是太猖狂了。" :),
        (: command, "say 真不知道該怎麼對付牠們。" :),
        (: command, "sigh" :),
    }) );
}
void create()
{
    set_name("豹頭", ({ "bow head", "head", "_BOW_HEAD_" }));
    set_race("human");
    set_level(60);
    set("title","豹人族長");
    set("long", "豹族長老，在悠閒中眼神卻帶著一種悲痛。\n");
    set("age", 80);
    set("camp", "bow");
    set("gender", "male");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
        CYN"搖椅發出聲響...「喀..」\n"NOR,
    }) );
    setup();
}

int relay_say(object me, string arg)
{
    if( !objectp(me) || !stringp(arg) ) return 0;

    if( arg == "蒼之梟" || arg == "猖狂" ) {
        do_chat( ({
           (: command, "say 提到牠就讓我生氣。" :),
           (: command, "angry" :),
           (: command, "say 我年輕的時候就有一隻蒼之梟來過轟天瀑。" :),
           (: command, "say 結果被人稱「高手高手高高手」的我給打跑了。" :),
           (: command, "cac" :),
           (: command, "eh _BOW_HEAD_" :),
           (: command, "say 不對..不是要說這個。" :),
           (: command, "say 是牠們最近居然又跑來佔領轟天瀑。" :),
           (: command, "say 已經殺死我們不少去轟天瀑修練的族人了！" :),
           (: command, "say 我也老了拿牠們沒辦法拉！" :),
           (: command, "say 真是不知道該怎麼辦才好..." :),
        }) );
        return 1;
    }
    if( arg == "高手高手高高手" ) {
        do_chat( ({
           (: command, "?" :),
           (: command, "say 那是我年輕時候的事了。" :),
           (: command, "say 當年豹族這裡還是隱居的部落地區。" :),
           (: command, "say 結果蒼之梟群第一次攻進我村，一時間大家都無法抵抗。" :),
           (: command, "say 剛好有位名叫包龍星的獵人公會成員來到這裡。" :),
           (: command, "say 就使用他的念能力「吵架王」將那群蒼之梟趕離了村子。" :),
           (: command, "say 後來我便跟隨他和他的隨從有為，一起對抗蒼之梟。" :),
           (: command, "say 等蒼之梟們離開後，包龍星居然將功勞全推給了我。" :),
           (: command, "say 所以才有這個高手的稱號...其實有點言過其實了。" :),
        }) );
        return 1;
    }
    if( arg == "包龍星" ) {
        do_chat( ({
           (: command, "say 他是獵人公會的成員，幫了我們豹族很大的忙。" :),
           (: command, "say 也因為他，豹族才會與獵人公會有協定。" :),
           (: command, "say 總之他是我們村子的恩人。" :),
        }) );
        return 1;
    }
    if( arg == "有為" ) {
        do_chat( ({
           (: command, "say 包龍星的跟班。" :),
           (: command, "say 好像使用一種名叫「黃金右腳」的念能力。" :),
           (: command, "say 實力可以說是深不可測。" :),
        }) );
        return 1;
    }
    return 1;
}
