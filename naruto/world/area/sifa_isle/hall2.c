#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�㥧�㴵�G�Ө��Y");
    set("long", @LONG
�㥧�㴵�j�U�G�Ӫ����D�A���D�W�������Τl�C
LONG);

    set("exits", ([
        "west" : __DIR__"hall1.c",
        "east" : __DIR__"hall3.c",
        "north" : __DIR__"house1.c",
        "south" : __DIR__"house2.c",
    ]));
    setup();
}