#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "海兵訓練場(８)");
    set("long", @LONG
這裡擺放了幾個假人，可以在這裡練技格鬥技能。
LONG);

    set("exits", ([
        "east" : __DIR__"prac9",
        "west" : __DIR__"prac7",
        "north" : __DIR__"prac5",
        "south" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 30,
                     "y_axis" : 37,
                  ]),
    ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));
    setup();
}
