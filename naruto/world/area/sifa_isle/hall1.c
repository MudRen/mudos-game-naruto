#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�㥧�㴵�G�Ө��Y");
    set("long", @LONG
�㥧�㴵�j�U�G�Ӫ����D�A���D�W�������Τl�C
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