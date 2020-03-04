#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "海兵訓練場(４)");
    set("long", @LONG
這裡擺放了幾個假人，可以在這裡練技格鬥技能。
LONG);

    set("exits", ([
        "east" : __DIR__"prac5",
        "north" : __DIR__"prac1",
        "south" : __DIR__"prac7",
        "west" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 27,
                     "y_axis" : 34,
                 ]),
    ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));
    setup();
}
