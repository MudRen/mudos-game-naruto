#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "海軍船操舵室");
        set("long", @LONG
裡面空蕩蕩的沒有半個人，儀器和各種用具也是放在一旁的桌子
上，也許是表示這艘船艦暫時不會航行吧。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"naval3.c",
                       "x_axis" : 10,
                       "y_axis" : 18,
                  ]),
    ]));
    setup();
}
