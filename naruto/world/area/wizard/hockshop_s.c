#include <room.h>

inherit HOCKSHOP;

void create()
{
        set("short", "天上掉下來的當舖");
        set("long", @LONG
天上人間的當舖，一個相當神秘的地方。
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 5,
                       "y_axis" : 40,
                  ]),
    ]));

    setup();
}
