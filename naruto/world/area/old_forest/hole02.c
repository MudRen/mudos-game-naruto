#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","洞窟內");
    set("long", @long
沒想到走沒幾步，居然就已經到底了。洞窟的底部只有一個看不
見底的大洞，你嘗試丟石頭下去測試深度，但是卻一點回音也沒有傳
回，你不放棄的在大洞附近摸索，終於在邊邊找到了一條粗繩，如果
不怕死的話也許可以爬(climb)下去瞧瞧....
long);
    set("exits", ([
        "north" : __DIR__"hole01.c",
    ]));
    set("detail", ([
        "粗繩": "就算用刀去砍也毫無損傷的堅硬粗繩，應該是土著所製作的吧。",
    ]));
    set("no_recall", 1);
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    if( arg == "粗繩") {
        message_vision("$N抓住繩頭，身手矯健的爬了下去。\n", this_player());
        this_player()->move(__DIR__"hole03.c");
        message_vision("$N終於爬到底端，累的滿頭大汗。\n", this_player());
        return 1;
    }
    return notify_fail("你想爬什麼東西？\n");
}
