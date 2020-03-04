#include <npc.h>
#include <ansi.h>

void to_do_say()
{
    do_chat( ({
        (: command, "say 唉喲...痛死我了..." :),
        (: command, "say 可惡的黑豬跑這麼快...害我跌了一跤。" :),
        (: command, "cry" :),
    }) );
}
void create()
{
    set_name("泰斯特", ({ "tai site", "site" }) );
    set_race("human");
    set_level(5);
    set("nickname", "豬大師");
    set("age", 25);
    set("long", "追逐豬而努力不懈的男人，可惜現在弄的滿身是傷無法動彈。\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }));
    setup();
}
