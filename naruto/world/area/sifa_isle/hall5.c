#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�㥧�㴵�G�Ө��Y");
    set("long", @LONG
�㥧�㴵�j�U�G�Ӫ����D�A���D�W�������Τl�C
LONG);

    set("exits", ([
        "west" : __DIR__"hall4.c",
        "south" : ([ "filename" : __DIR__"aineaisi.c",
                     "x_axis" : 26,
                     "y_axis" : 2,
                  ]),
        ]));
    setup();
}