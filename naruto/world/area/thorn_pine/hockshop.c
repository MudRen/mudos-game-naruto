#include <room.h>

inherit HOCKSHOP;

void create()
{
        set("short", "���E");
        set("long", @LONG
�o�̬O�\�ڪ����E...
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"village.c",
                     "x_axis" : 9,
                     "y_axis" : 6,
                  ]),
    ]));
        setup();
}
