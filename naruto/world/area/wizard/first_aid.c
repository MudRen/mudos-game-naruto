#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "急救");
    set("long", "一間小小間的急診室。\n");

    set("objects", ([ "/world/npc/first-aid-teacher": 1 ]));
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 29,
                       "y_axis" : 28,
                  ]),
        "south" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 26,
                       "y_axis" : 31,
                  ]),
        "west" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 23,
                       "y_axis" : 28,
                  ]),
        "north" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 26,
                       "y_axis" : 25,
                  ]),
    ]));

    setup();
}
