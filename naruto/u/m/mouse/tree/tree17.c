#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","古森枝部");

    set("long", @long
這裡似乎是樹的中心附近，樹枝都順著樹幹往上攀升，也許可以
往上爬，爬到更高的樹層去。
long);
    set("exits", ([
        "west" : __DIR__"tree16.c",
        "east" : __DIR__"tree18.c",
    ]));
    set("detail", ([
        "樹枝": "一條看似堅固的樹枝，可以試著攀爬(climb)上去。",
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
    message_vision("$N抓住牢固的樹枝，快速的爬了上去。\n", this_player());
    this_player()->move(__DIR__"tree24.c");
    message_vision("$N從下面爬了上來。\n", this_player());
    return 1;
    }
    return notify_fail("你想爬什麼東西？\n");
}
