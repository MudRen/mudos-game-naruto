#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIK"測試間"NOR);
    set("long", @long
這裡沒有路！想出去嗎？自己想辦法吧！
long);
    set("exits", ([
    ]));
    set("detail", ([
        "出去": "輸入"HIY"["HIW"gohome"HIY"]"NOR"就對啦！",
    ]));

    setup();
}
void init()
{
    add_action("do_gohome", "gohome");
}
int do_gohome(string arg)
{
    message_vision(HIY"$N被一隻大手抓了出去。\n"NOR, this_player());
    this_player()->move(__DIR__"workroom.c");
    message_vision(HIY"$N眼前一亮就出現在這裡。\n"NOR, this_player());
    return 1;
}
