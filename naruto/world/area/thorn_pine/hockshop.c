#include <room.h>

inherit HOCKSHOP;

void create()
{
        set("short", "當舖");
        set("long", @LONG
這裡是豹族的當舖...
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"village.c",
                     "x_axis" : 9,
                     "y_axis" : 6,
                  ]),
    ]));
        setup();
}
