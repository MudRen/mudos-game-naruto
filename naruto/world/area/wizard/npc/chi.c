#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("易口癡", ({ "yi kou chi master", "master" }) );
    set_race("human");
    set_level(40);
    set_class("superior");
    set("age", 25);
    set("title", "新手導師");
    set("long", "他是一位新手導師，教導你如何在這個世界闖盪！如果你想要接受他\n"
                "的指導，請輸入指令：ask master\n"
                "若想進一步瞭解指令的用法，請輸入：help ask\n"
    );
    setup();
}
void init()
{
    if( this_player()->query_class() == "commoner" && userp(this_player()) ) {
        do_chat( ({ 
            (: command, "say 你好啊，這位可面生很，是新來的嗎？" :), 
            (: command, "say 若要接受新手教學請輸入指令：ask master" :),
            (: command, "say 若要查詢說明文件請輸入指令：help" :),
        }) );
    }
    return;
}
