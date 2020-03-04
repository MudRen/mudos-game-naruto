#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "左側一樓");
    set("long", @LONG
在艾尼艾斯大廳左側的樓梯，不知道上面有什麼...
LONG);
    set("exits", ([
        "up" : __DIR__"left2.c",
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 33,
                     "y_axis": 26,
                  ]),
    ]));
    setup();
}
