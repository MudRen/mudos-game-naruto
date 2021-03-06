#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","古森上枝");

    set("long", @long
蜂擁而上的土著讓人累的喘不過氣，偶然間發現旁邊的樹枝下面
好像還有樹枝可走，雖然不清楚是通向哪裡，但起碼可以避開這些緊
追不捨的土著吧。
long);
    set("exits", ([
        "west" : __DIR__"tree28.c",
        "east" : __DIR__"tree30.c",
    ]));
    set("detail", ([
        "樹枝": "快爬(climb)下去吧！土著就要追來了。",
    ]));
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    if( arg == "樹枝") {
    message_vision("$N趁著土著不注意，偷偷的爬了下去。\n", this_player());
    this_player()->move(__DIR__"tree34.c");
    message_vision("$N偷偷摸摸的從上面爬了下來。\n", this_player());
    return 1;
    }
    return notify_fail("你想爬什麼東西？\n");
}
