#include <room.h>

inherit HOCKSHOP;

void create()
{
        set("short", "�ѤW���U�Ӫ����E");
        set("long", @LONG
�ѤW�H�������E�A�@�Ӭ۷������a��C
LONG);
    set("exits", ([
        "east" : ([ "filename" : __DIR__"wizard.c",
                       "x_axis" : 5,
                       "y_axis" : 40,
                  ]),
    ]));

    setup();
}
