#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "猿山連合屋壹樓");
        set("long", @LONG
這裡是猿山連合軍的海賊船室內，一樓似乎是「打撈王」人猿的
房間，牆壁上掛著一些人猿找到的寶物。
LONG);
    set("exits", ([
        "up" : __DIR__"monkey2.c",
        "south" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 24,
                       "y_axis" : 28,
                  ]),
    ]));
    setup();
}
