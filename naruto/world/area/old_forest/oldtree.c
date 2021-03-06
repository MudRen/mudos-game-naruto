#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"神木中心"NOR);

    set("long", @long
放眼望去是一片廣大的空中庭院，原來神木的樹枝與葉已經擴展
到整片巨木森林，所以才使得下面完全一片漆黑，陽光都透不進去。
如果想離開可以順著原路爬下去。
long);
    set("exits", ([
        "west" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 4,
                      "y_axis": 16,
                 ]),
        "east" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 6,
                      "y_axis": 16,
                 ]),
        "north" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 5,
                      "y_axis": 15,
                 ]),
        "south" : ([ "filename": __DIR__"monkey.c",
                      "x_axis": 5,
                      "y_axis": 17,
                 ]),
    ]));
    set("detail", ([
        "樹枝": "粗壯的神木古根，想離開就爬(climb)下去吧。",
    ]));
    setup();
}
void init()
{
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    if( arg == "樹枝") {
    message_vision("$N緩緩的爬了下去。\n", this_player());
    this_player()->move(__DIR__"tree30.c");
    message_vision("$N從上頭爬了下來。\n", this_player());
    return 1;
    }
    return notify_fail("你想爬什麼東西？\n");
}
