#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void to_do_say()
{
    do_chat( ({ 
        (: command, "say 最近的海賊愈來愈猖獗..." :),
        (: command, "say 都怪我老的太早了！" :),
        (: command, "sigh" :),
    }) );
}
void create()
{
    set_name("老人", ({ "oldman" }) );
    set_race("human");
    set_level(1);
    set("age", 80);
    set("long", "退役的海軍老兵，因為曾為海軍立下不少功\，加上退役後他自己請求\n"
                "在司法島上讓他蓋\房子居住，所以後來便住在這海邊小屋了。\n");

    // 一般時動作
    set("chat_chance", 3);
    set("chat_msg", ({
        (: to_do_say :),
    }) );

    set_goods(1, "wp", 57, -1, -1);
    setup();
}
