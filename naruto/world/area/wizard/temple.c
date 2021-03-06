#include <ansi.h>

inherit ROOM;


void create()
{
    set("short", "土地公廟");
    set("long", "一間香火鼎盛的土地公廟，你有是沒事可以來燒個香，俗話說得好：\n"
                "有燒香有保佑，沒燒香會出事情啊。\n" );

    set("objects", ([ __DIR__"npc/temple_master": 1 ]));
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 21,
                       "y_axis" : 36,
                  ]),
        "south" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 18,
                       "y_axis" : 39,
                  ]),
        "west" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 15,
                       "y_axis" : 36,
                  ]),
        "north" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 18,
                       "y_axis" : 33,
                  ]),
    ]));

    setup();
}
