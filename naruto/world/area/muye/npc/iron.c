#include <npc.h>
#include <ansi.h>

inherit F_VENDOR;

void create()
{
    set_name("鐵器老闆", ({ "iron boss", "boss" }) );
    set_race("human");
    set_level(50);
    set("age", 61);
    set("long", "顧著燒紅的打鐵爐，專心製作器具的老師傅。\n");
    set("chat_chance", 2);
    set("chat_msg", ({
        CYN"鐵器老闆正專心地製作好用的器具中...\n"NOR,
        (: command, "sweat" :),
    }));
    set_goods(1, "wp", 74, 10, -1);
    set_goods(2, "wp", 15, 10, -1);
    set_goods(3, "wp", 57, 10, -1);
    setup();
}
void relay_say(object ob, string arg)
{
    object item;

    if( arg == "十字鎬" )  {
        do_chat(({
            (: command, "say 是在這裡買沒錯！" :),
            (: command, "say 但是最近買十字鎬的人愈來愈多，已經有些缺貨了。" :),
            (: command, "say 所以我又收了幾個學徒專門製作這樣道具。" :),
            (: command, "say 可惜他們的技術不是很好阿，所以品質沒有保障喔！" :),
            (: command, "say 我已經將價格降低到兩千兩銀子了。" :),
            (: command, "say 有需要就跟我買吧。" :),
            (: command, "wink" :),
        }));
        return;
    }
}
