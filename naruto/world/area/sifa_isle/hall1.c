#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "艾尼艾斯二樓走廊");
    set("long", @LONG
艾尼艾斯大廳二樓的走道，走道上有六間屋子。
LONG);

    set("exits", ([
        "east" : __DIR__"hall2.c",
        "south" : ([ "filename" : __DIR__"aineaisi.c",
                     "x_axis" : 3,
                     "y_axis" : 2,
                  ]),
        ]));
    setup();
}