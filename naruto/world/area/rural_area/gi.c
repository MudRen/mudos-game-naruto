#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", HIR"���򪺮a"NOR);
    set("long", @LONG
�ܴ��q���a�A�ߤ@�S�O���a��N�O�Ҧ����a�㳣�O���⪺�A����
�O����⦳�S����n�٬O�����L����]�H
LONG);
    set("exits", ([
        "south" : ([ "filename" : __DIR__"area.c",
                       "x_axis" : 31,
                       "y_axis" : 17,
                  ]),
    ]));
    set("objects", ([
        __DIR__"npc/gi.c" : 1,
    ]));
    setup();
}
