#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�㥧�㴵�G�Ө��Y");
    set("long", @LONG
�㥧�㴵�j�U�G�Ӫ����D�A���D�W�������Τl�C
LONG);

    set("exits", ([
        "west" : __DIR__"hall2.c",
        "east" : __DIR__"hall4.c",
        "north" : __DIR__"house3.c",
        "south" : __DIR__"house4.c",
    ]));
    setup();
}