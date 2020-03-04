#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "海兵訓練場(２)");
    set("long", @LONG
這裡擺放了幾個假人，可以在這裡練技格鬥技能。
LONG);

    set("exits", ([
        "west" : __DIR__"prac1",
        "east" : __DIR__"prac3",
        "south" : __DIR__"prac5",
        "north" : ([ "filename" : __DIR__"sifa.c",
                     "x_axis" : 30,
                     "y_axis" : 31,
                  ]),
        ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));
    setup();
}
