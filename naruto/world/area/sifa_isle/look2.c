#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "瞭望台二樓");
    set("long", @LONG
二樓堆放了一些雜物...雜物上都已經發霉了...
LONG);

    set("exits", ([
        "up" : __DIR__"look3.c",
        "down" : __DIR__"look1.c",
    ]));
    setup();
}
