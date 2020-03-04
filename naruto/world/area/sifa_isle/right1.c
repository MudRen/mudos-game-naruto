#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "右側一樓");
    set("long", @LONG
在艾尼艾斯大廳右側的樓梯，不知道上面有什麼...
LONG);
    set("exits", ([
        "up" : __DIR__"right2.c",
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 57,
                     "y_axis": 26,
                  ]),
    ]));
    setup();
}
