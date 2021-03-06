#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","古森上枝");

    set("long", @long
陽光可以稍微透進，讓人了解這古森的複雜。抬頭望去可以看到
上面還有一片更大的葉林，但是剛才所爬的樹枝卻沒有繼續向上延伸
，只能往下爬而已。
long);
    set("exits", ([
        "west" : __DIR__"tree25.c",
        "east" : __DIR__"tree27.c",
    ]));
    set("detail", ([
        "樹枝": "剛才爬上來的樹枝，想離開就爬(climb)下去吧。",
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
    message_vision("$N抓住牢固的樹枝，順勢溜了下去。\n", this_player());
    this_player()->move(__DIR__"tree20.c");
    message_vision("$N從上面溜了下來。\n", this_player());
    return 1;
    }
    return notify_fail("你想爬什麼東西？\n");
}
