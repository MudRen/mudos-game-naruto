#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "蛋室");
        set("long", @LONG
這裡就是蛇族的蛋室了，裡面的溫度比外面高出許多，四周都塞
滿了稻草來溫暖房內，不過因為稻草堆的太滿了，讓人看不出來裡面
到底還有沒有蛋。不過現在這裡連一個守衛都沒有，可見現在一定沒
有蛋在裡面。
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"marsh.c",
                       "x_axis" : 24,
                       "y_axis" : 13,
                  ]),
    ]));
    setup();
}
