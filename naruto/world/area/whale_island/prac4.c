
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "練習場(４)");
        set("long", @LONG
這裡擺放了幾個假人，可以在這裡練技格鬥技能。
LONG);

        set("exits", ([
        "west" : ([ "filename" : __DIR__"area.c",
                     "x_axis" : 22,
                     "y_axis" : 17,
                  ]),                           
                "north" : __DIR__"prac1",               
                "east" : __DIR__"prac5",                
                "south" : __DIR__"prac7",               
        ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));

        setup();
}

