#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "海兵訓練場(５)");
    set("long", @LONG
這裡擺放了幾個假人，可以在這裡練技格鬥技能。
LONG);

    set("exits", ([
        "east" : __DIR__"prac6",
        "north" : __DIR__"prac2",
        "south" : __DIR__"prac8",
        "west" : __DIR__"prac4",
    ]));

    set("objects", ([
        _DIR_NPC_"stake.c": 4,
    ]));
    setup();
}
