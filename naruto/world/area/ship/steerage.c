#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "操舵室");
        set("long", @LONG
黃金梅利號的操舵室，原本應該只有舵和桌子的房間，現在卻被
堆的滿滿，因為這裡同時也是騙人布的研發室。
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"lufi.c",
                       "x_axis" : 8,
                       "y_axis" : 24,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/usopp.c" : 1,
        __DIR__"npc/chopper.c" : 1,
    ]));
    setup();
}
