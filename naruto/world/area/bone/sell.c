#include <room.h>

inherit HOCKSHOP;

void create()
{
        set("short", "���E");
        set("long", @LONG
�o�̬O�˨��@�ڪ����E...
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"bone.c",
                     "x_axis" : 32,
                     "y_axis" : 15,
                  ]),
    ]));
    setup();
}
