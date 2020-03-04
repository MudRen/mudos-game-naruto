#include <ansi.h>

inherit ROOM;

int i;

void create()
{
        set("short", "雜物間");
        set("long", @LONG
堆滿了雜物的小房間，一點火可能就一發不可收拾。
LONG);
    set("exits", ([
        "north" : ([ "filename" : __DIR__"music.c",
                       "x_axis" : 34,
                       "y_axis" : 5,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/san.c" : 1,
    ]));
    setup();
}
