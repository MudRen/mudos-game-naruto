#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�k���@��");
    set("long", @LONG
�b�㥧�㴵�j�U�k�����ӱ�A�����D�W��������...
LONG);
    set("exits", ([
        "up" : __DIR__"right2.c",
        "south" : ([ "filename": __DIR__"sifa.c",
                     "x_axis": 57,
                     "y_axis": 26,
                  ]),
    ]));
    setup();
}