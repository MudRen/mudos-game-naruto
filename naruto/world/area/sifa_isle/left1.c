#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�����@��");
    set("long", @LONG
�b�㥧�㴵�j�U�������ӱ�A�����D�W��������...
LONG);
    set("exits", ([
        "up" : __DIR__"left2.c",
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 33,
                     "y_axis": 26,
                  ]),
    ]));
    setup();
}
