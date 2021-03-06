#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("鑄大師", ({ "found master", "master" }) );
    set_race("human");
    set_level(50);
    set("age", 35);
    set("long", "打著赤膊露出健美的肌肉，上面沁著辛勞的汗漬。\n");
    set("chat_chance", 2);
    set("chat_msg", ({
        CYN"鑄大師敲打著武器。\n"NOR,
        (: command, "say 合成的「武器」平常是買不到的。" :),
        (: command, "say 想知道「合成」的技巧嗎？" :),
    }));
    setup();
}
void relay_say(object ob, string arg)
{
    object item;

    if( arg == "合成" )  {
        do_chat(({
            (: command, "nod" :),
            (: command, "say 合成，簡單說就是強化一把武器，在武器上融上新的合金。" :),
            (: command, "say 不過一般能使用強化卷軸的武器不太需要用到這種技術。" :),
            (: command, "say 所以目前來說能使用這種技術的武器可以說是少之又少。" :),
            (: command, "lick" :),
            (: command, "say 合成必須要到特定的工作室中才能進行。" :),
            (: command, "say 我這裡也有一間工作室，但是人多起來可是沒辦法同時合成的。" :),
            (: command, "say 合成需要用到一些特別的礦物，像煤礦等等的拉。" :),
            (: command, "think" :),
            (: command, "say 採集的地點是血腥荒野的山洞中，那裡含有豐富的礦產資源。" :),
            (: command, "say 想要採集礦產當然不可能徒手挖，需要使用特殊工具「十字鎬」" :),
            (: command, "say 沒記錯的話木葉村鐵鋪好像有賣...太久沒去有點忘記了。" :),
            (: command, "say 因為現在都找代工去幫我挖礦了..." :),
            (: command, "blush" :),
        }));
        return;
    }
    if( arg == "武器" )  {
        do_chat(({
            (: command, "qk" :),
            (: command, "say 合成用的武器，必須能夠抵抗合成時的高溫。" :),
            (: command, "say 一般我們所製作的武器都不適合。" :),
            (: command, "say 不過這類的合成武器，卻也因此讓卷軸的功用不能發揮。" :),
            (: command, "say 可以說是有利有弊。" :),
            (: command, "shrug" :),
            (: command, "say 我也只為幾個人合成過武器。" :),
            (: command, "say 就我所知，他們的武器都是來自於土著村裡。" :),
            (: command, "say 不過我也拿過刺槍或是弓等等土著武器試過，結果總是失敗的。" :),
            (: command, "say 讓我不禁懷疑那些武器的出處。" :),
            (: command, "stare" :),
        }));
        return;
    }
}
