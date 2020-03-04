#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "一間破屋");
        set("long", @LONG
殘破不勘的屋子，門早就不知道飛到哪去了，裡面放了一些奇怪
的食物，不知道是誰殘留下來的東西...
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 10,
                       "y_axis" : 17,
                  ]),
        "west" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 9,
                       "y_axis" : 18,
                  ]),
        "southeast" : ([ "filename" : __DIR__"fight.c",
                       "x_axis" : 11,
                       "y_axis" : 19,
                  ]),
    ]));
    setup();
}
