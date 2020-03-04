#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "倉庫");
    set("long", @LONG
商人家旁邊的大倉庫，進來之後只見四周的門都被鎖上了，根本
沒辦法打開，應該都是商人要販賣的物品吧。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 35,
                       "y_axis" : 7,
                  ]),
    ]));
    setup();
}
