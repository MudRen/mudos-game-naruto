#include <room.h>

inherit HOCKSHOP;

void create()
{
        set("short", "當舖");
        set("long", @LONG
這裡是竹取一族的當舖...
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"bone.c",
                     "x_axis" : 32,
                     "y_axis" : 15,
                  ]),
    ]));
    setup();
}
