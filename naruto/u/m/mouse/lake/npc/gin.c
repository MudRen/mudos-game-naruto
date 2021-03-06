#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("方糖勁", ({ "fonton gin", "gin" }) );
    set_race("human");
    set("gender", "male"); 
    set_level(1);
    set("age", 30);
    set("long", "賊頭賊腦的樣子，一看就一副奸樣。\n");
    set("chat_chance", 7);
    set("chat_msg", ({
       (: command, "say 那個古董商人太可惡了！居然想坑我的錢！" :),
       (: command, "say 這張奇怪的紙是我下遺跡去好不容易才找到的紙！" :),
       (: command, "say 那個古董商人居然說是廢紙！還叫我賣他一兩銀子！" :),
       (: command, "say 這破花瓶修一修也可以賣個好價阿！那古董商人居然不收！" :),
    }));
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
       (: command, "say 哇！殺人阿！" :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":43, "amount":1, "p1":30, "p2":100 ]),     // 信紙
        ([ "type":"obj", "id":50, "amount":1, "p1":80, "p2":100 ]),     // 機關紙
    }) );
    setup();
}
void relay_say(object ob, string arg)
{
    if( arg == "奇怪的紙" || arg == "廢紙" || arg == "紙" )  {
        do_chat(({ 
           (: command, "say 你也想要紙嗎？" :),
           (: command, "say 我就偏不給你！" :),
           (: command, "cac" :),
           NOR"方糖勁說道﹕"HIG"阿∼我有這張重要的紙阿∼\n"NOR,
           NOR"方糖勁說道﹕"HIG"阿∼我就是不給你阿∼\n"NOR,
           (: command, "jump" :),
           NOR"方糖勁說道﹕"HIG"阿∼我有這張重要的紙阿∼\n"NOR,
           NOR"方糖勁說道﹕"HIG"阿∼我就是不給你阿∼\n"NOR,
           (: command, "jump" :),
           NOR"方糖勁說道﹕"HIG"打我阿∼笨蛋∼\n"NOR,
        }));
    }
    if( arg == "破花瓶" )  {
        do_chat(({ 
           CYN"方糖勁搖了搖食指。\n"NOR,
           (: command, "say 大人說的不對喔！" :),
           (: command, "say 破可破，非常破" :),
           (: command, "say 你的破了，我的可沒破" :),
           (: command, "say 你沒看過，怎麼知道我的花瓶破阿。" :),
           (: command, "think" :),
           NOR"方糖勁說道﹕"HIG"算了∼我一介讀書人不跟你吵這個話題∼\n"NOR,
           (: command, "gy fonton gin" :),
        }));
    }
}
int accept_fight(object ob)
{
    do_chat(NOR"方糖勁說道﹕"HIG"早就知道你不敢動手∼哈哈哈！"NOR"\n");
    return 0;
}
