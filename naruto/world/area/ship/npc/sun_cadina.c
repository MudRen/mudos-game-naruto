#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("卡迪那", ({ "cadina" }) );
    set_race("human");
    set_level(25);
    set("title",HIR"三日月"NOR);
    set("nickname", "領航員");
    set("gender", "male");
    set("class","thief_sea");
    set("camp", "robber");
    set("age", 21);
    set("long", "有點胖胖的海賊船員，看他熟練的操船技巧，應該是領航員吧。\n");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say 喂！有沒有發現什麼島嶼？！" :),
        (: command, "say 上次那個島怎麼找不到了...很多「火山」的那座阿..." :),
        (: command, "peer" :),
    }));
    set("set_drop", ({
        ([ "type":"wp", "id":15, "amount":1, "p1":70, "p2":100 ]),        // 釣干
        ([ "type":"wp", "id":57, "amount":1, "p1":70, "p2":100 ]),        // 魚叉
        ([ "type":"wp", "id":39, "amount":1, "p1":25, "p2":100 ]),        // 軟槍
        ([ "type":"wp", "id":42, "amount":1, "p1":35, "p2":100 ]),        // 刺木槍
    }) );
    setup();
    carry_object("/world/area/thorn_pine/npc/wp/thorn_lance.c")->wield("twohanded");
}
void relay_say(object ob, string arg)
{
    if( arg == "火山" )  {
        do_chat(({
            (: command, "shrug" :),
            (: command, "say 我也不懂為什麼，很久以前我們到過一個火山島嶼。" :),
            (: command, "say 當時船長上岸後只說那沒寶藏，大夥就閃人了。" :),
            (: command, "say 不過上次去過死亡碉堡後隔沒幾天。" :),
            (: command, "say 船長就一直吵著要找這座島。" :),
            (: command, "say 不過那座島小不拉機的叫我去哪找阿..." :),
            (: command, "sigh" :),
        }));
        return;
    }
}
